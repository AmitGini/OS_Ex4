#include "Singleton.hpp"

Singleton *Singleton::instance = nullptr;
std::mutex Singleton::mtx;

Singleton *Singleton::getInstance()
{
    std::lock_guard<std::mutex> lock(mtx);
    if (instance == nullptr)
    {
        instance = new Singleton();
    }
    return instance;
}
