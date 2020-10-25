#include<iostream>
#include"Mutex.hpp"
#include"SharedResource.hpp"
#include<vector>
int main(){
  
    min::SharedResource<int> sh(0);
    //std::cout<<sh.Get()->Get()<<std::endl;
    //std::cout<<sh.getT()<<std::endl;
    //std::cout<<sh.get()<<std::endl;
    sh.GetWithLock();
    std::cout<<"end"<<std::endl;
    min::SharedResource<std::vector<int>> re; 
    
    //return 0;

}