#include"Mutex.hpp"

namespace min{

    void MutexLock::Lock(){
        auto test = std::this_thread::get_id();
        if(this->_threadID == test){
            std::cout<<"Dup lock: "<<test<<"=="<<_threadID<<std::endl;
            return;
        }
        _threadID = test;
        std::cout<<"Thread id: "<<test<<std::endl;
        _mutex.lock();
       


    }
    void MutexLock::Unlock(){
        std::cout<<"Call unlock "<<std::endl;
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