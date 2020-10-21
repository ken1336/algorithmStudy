#include "Lock.hpp"

namespace min
{

    class MutextLock : public min::LockBase
    {

    private:
        virtual void _Lock();

    public:
        virtual void Lock();
        virtual void Unlock();
        virtual void LockWrite();
        virtual void UnLockWrite();
        virtual void LockRead();
        virtual void UnLockRead();
    };
} // namespace min