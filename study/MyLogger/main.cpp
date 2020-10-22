#include<iostream>
#include"Mutex.hpp"

int main(){

    min::MutexLock test{};
    test.Lock();
    test.Lock();
    test.Unlock();
    return 0;

}