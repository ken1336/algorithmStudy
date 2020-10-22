#include"SpinLock.hpp"

namespace min{

    void SpinLock::_Lock(){
        __asm ("cli"); 
        flag.test_and_set(std::memory_order_acquire);
    }
}