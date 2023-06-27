#pragma once
#include "lockqueue.h"
#include <string>
#include <unistd.h>
#include <string.h>

// 定义宏 LOG_INFO("xxx %d %s", 20, "xxxx")
#define LOG_INFO(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance(); \
        char c[1024] = {0}; \
        char str[1048] = "[info] "; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        strcat(str, c); \
        logger.Log(str); \
    } while(0) \

#define LOG_ERR(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance(); \
        char c[1024] = {0}; \
        char str[1048] = "[error] "; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        strcat(str, c); \
        logger.Log(str); \
    } while(0) \

// 定义日志级别
enum LogLevel
{
    INFO,  // 普通信息
    ERROR, // 错误信息
};


// 为什么需要异步日志系统
// 写日志信息属于磁盘I/O，速度相对于cpu执行很慢，不能与网络IO同步进行处理
// 不能把写日志的时间也算入网络IO业务处理流程中




// Mprpc框架提供的日志系统
class Logger
{
public:
    // 获取日志的单例
    static Logger& GetInstance();

    // 写日志
    void Log(std::string msg);
private:
    LockQueue<std::string>  m_lckQue; // 日志缓冲队列

    Logger();
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
};