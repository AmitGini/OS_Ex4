#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>

class Singleton
{
public:
    static Singleton *getInstance();
    virtual ~Singleton() {}

protected:
    Singleton() {}

private:
    static Singleton *instance;
    static std::mutex mtx;
};

#endif
