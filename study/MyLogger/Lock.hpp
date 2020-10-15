#include<atomic>
#include<mutex>

class MinLock{

    private:
    virtual void _Lock()=0;

    public:
    virtual void Lock() = 0;
    virtual void Unlock() = 0;
    virtual void LockWrite()=0;
    virtual void UnLockWrite()=0;
    virtual void LockRead()=0;
    virtual void UnLockRead()=0;




}