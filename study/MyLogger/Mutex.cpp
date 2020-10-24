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
        _threadID=0;
        _mutex.unlock();
    }
    
    void MutexLock::LockWrite(){

    }
    void MutexLock::UnLockWrite(){

    }
    void MutexLock::LockRead(){
        
    }
    void MutexLock::UnLockRead(){}
}