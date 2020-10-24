#include "Lock.hpp"
#include<iostream>
#include<thread>
#include<mutex>
namespace min
{

    class MutexLock : public min::LockBase
    {

    private:
        std::mutex _mutex;
        std::thread::id _threadID;
        int _recursiveLockCount;
    public:
        MutexLock(){};
        void Lock();
        void Unlock();
        virtual ~MutexLock() = default;
    };
} // namespace min