
#include<atomic>

using namespace std;

#ifdef _WIN32
#include <intrin.h>
#pragma intrinsic(_InterlockedExchange)
#define LOCK_TEST_AND_SET(_lock) _InterlockedExchange(&_lock, 1)
#define LOCK_RELEASE(_lock) _InterlockedExchange(&_lock, 0)
#else
#define LOCK_TEST_AND_SET(_lock) __sync_lock_test_and_set(&_lock, 1)
#define LOCK_RELEASE(_lock) __sync_lock_release(&_lock)
#endif

class Spinlock {
private:
    std::atomic_flag flag;
    volatile long _write = 0;
    volatile atomic_int _read;

    void _lock() {
        while (true) {
            if (!LOCK_TEST_AND_SET(_write))
                return;
            while (_write);
        }
    }

public:
    Spinlock() : _read(false), flag(ATOMIC_FLAG_INIT) { }

    inline void lock() {
        while (flag.test_and_set(std::memory_order_acquire));
    }

    inline void unlock() {
        flag.clear(std::memory_order_release);
    }

    inline void lockWrite() {
        bool w = false;
        while (true) {
            if (!w && !LOCK_TEST_AND_SET(_write)) {
                w = true;
            }
            if (w && !_read) {
                return;
            }
            while ((!w && _write) || _read);
        }
    }

    inline void unlockWrite() {
        LOCK_RELEASE(_write);
    }

    inline void lockRead() {
        lockWrite();
        _read++;
        unlockWrite();
    }

    inline void unlockRead() {
        _read--;
    }
};