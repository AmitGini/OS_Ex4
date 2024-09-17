#ifndef GUARD_HPP
#define GUARD_HPP

#include <mutex>

class Guard
{
public:
    explicit Guard(std::mutex &mtx) : mtx(mtx)
    {
        mtx.lock();
    }
    ~Guard()
    {
        mtx.unlock();
    }

private:
    std::mutex &mtx;
};

#endif // GUARD_H
