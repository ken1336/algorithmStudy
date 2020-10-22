#include <atomic>
#include <mutex>

namespace min
{

    class LockBase
    {
    private:
    public:
        virtual void Lock() = 0;
        virtual void Unlock() = 0;
        virtual ~LockBase() = default;
    };
    
} // namespace min
