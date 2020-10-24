#include<iostream>
#include"Mutex.hpp"
#include"SharedResource.hpp"
int main(){

    min::SharedResource sh(10);
    std::cout<<sh.getT()<<std::endl;
    return 0;

}