#include"Mutex.hpp"

namespace min{

    void MutexLock::Lock(){
        auto currentThread = std::this_thread::get_id();
        if(this->_threadID == currentThread){
            std::cerr<<"Lock duplicated"<<std::endl;
            return;
        }
        _threadID = currentThread;
        _mutex.lock();
       


    }
    void MutexLock::Unlock(){
        std::cout<<"Call unlock "<<std::endl;
        _mutex.unlock();
    }

}