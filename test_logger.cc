
#include "src/logger.h"








// g++ -o test_logger test_logger.cc ./src/logger.cc  -lpthread

int main() {

    std::thread t1([&]() {
        for (int i = 0; i < 10; ++i) {
            LOG_INFO("info log.");
            LOG_ERR("err log.");
        }
    });

    std::thread t2([&]() {
        for (int i = 0; i < 10; ++i) {
            LOG_INFO("info log.");
            LOG_ERR("err log.");
        }
    });

    std::thread t3([&]() {
        for (int i = 0; i < 10; ++i) {
            LOG_INFO("info log.");
            LOG_ERR("err log.");
        }
    });

    std::thread t4([&]() {
        for (int i = 0; i < 10; ++i) {
            LOG_INFO("info log.");
            LOG_ERR("err log.");
        }
    });


    std::thread t5([&]() {
        for (int i = 0; i < 10; ++i) {
            LOG_INFO("info log.");
            LOG_ERR("err log.");
        }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    getchar();

    return 0;
}