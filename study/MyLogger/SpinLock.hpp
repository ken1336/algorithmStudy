#include "Lock.hpp"
#include <atomic>
namespace min
{
    class SpinLock : public min::LockBase
    {
    private:
        std::atomic_flag flag;
        volatile long _write = 0;
        volatile std::atomic_int _read;

        virtual void _Lock();

    public:
        SpinLock() : _read(false), flag(ATOMIC_FLAG_INIT){};
        void Lock();
        void Unlock();
        void LockWrite();
        void UnLockWrite();
        void LockRead();
        void UnLockRead();
    };
} // namespace min