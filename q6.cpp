#include<iostream>


template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
  return t + u;
}


int main(){

    auto arg = "1";
    auto arg2 = 2;

    auto result = add(arg,arg2);
    std::cout<<result<<std::endl;
    
}