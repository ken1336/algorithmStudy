#include<iostream>
#include <type_traits>


struct sFoo{

    sFoo(int t){
        std::cout<<"constructor called"<<std::endl;
    }
    void test1(){

        std::cout<<"sFoo test function call"<<std::endl;
    }
    int test2(){
        return 0;
    }

};
class sFoo2el{
    public:
    sFoo2el(){
        std::cout<<"void arg type constructor called(default): "<<std::endl;
    }
    int f(){
        std::cout<<"called f"<<std::endl;
        return 0;
    }

};

class sFoo2el2 {
  public:
    sFoo2el2(int t){std::cout<<"int arg type constructor called: "<<t<<std::endl;}
    int f(){
        std::cout<<"called f"<<std::endl;
        return 0;
    }
};

template<typename T> 
class sFoo2{

    public:
    sFoo2(){
        std::cout<<"template class constructor called"<<std::endl;
    }
    // decltype(T().f()) call_f_and_return(T& t){
    //     return t.f();
    // }
    
    auto call_f_and_return(T& t){
        return t.f();
    }
};



template<class T>
typename std::result_of<T(int)>::type f(T& t)
{
    std::cout << "overload of f for callable T\n";
    return t(0);
}
int fn(int t ) {return t;}  

int foo1(){
    return 1;
}


// template<typename T>
// constexpr char* type(T a)
// {
    
//     if(std::is_same<decltype(a), double>::value)
//         return (char*)"double"; 
//     if(std::is_same<decltype(a), int>::value)
//         return (char*)"int"; 
//     if(std::is_same<decltype(a), char*>::value)
//         return (char*)"char array"; 
//     if(std::is_same<decltype(a), std::string>::value)
//         return (char*)"string"; 
//     if(std::is_same<decltype(a), char>::value)
//         return (char*)"char"; 
//     return (char*)"unknown";
// } 


template<typename T>
const char* type(T a)
{
    
    if(std::is_same<decltype(a), double>::value)
        return "double";
    if(std::is_same<decltype(a), int>::value)
        return "int"; 
    if(std::is_same<decltype(a), char*>::value)
        return "char array"; 
    if(std::is_same<decltype(a), std::string>::value)
        return "string"; 
    if(std::is_same<decltype(a), char>::value)
        return "char"; 
    return "unknown";
} 

template<typename T>
auto addSufix(T t) -> decltype(t){
    
    return t+"hello";
}

// template <typename T, typename U>
// auto add(T t, U u) -> decltype(t + u) {
//   return t + u;
// }

// template <typename T, typename U>
// int add(T t, U u) {
//   return t + u;
// }


template <typename T>
T add(T t, T u) {
  return t + u;
}


// template <>
// auto add<std::string>(std::string t, std::string u) -> decltype(t+u){
//     return t+u;
// }

int main(){
    //std::cout<<addSufix("test")<<std::endl;
    // std::cout<<addSufix<std::string>("test")<<std::endl;



    // std::cout<<add<std::string>("hello","world")<<std::endl;


    // typedef std::result_of<decltype(fn)&(int)>::type A; 
    // char* t = "hello";
    // std::string str = "hi";
    // int a =1;
    // std::cout<<type(str)<<std::endl;

    // sFoo(1);
    // decltype(sFoo(1).test2()) el2 = 10;
    // std::cout<<el2<<std::endl;
   
    // auto ff = sFoo2el();
    // auto sfoo2 = sFoo2<sFoo2el>();
    // sfoo2.call_f_and_return( ff);
    

    auto ff2 = sFoo2el2(1);
    auto sfoo22 = sFoo2<sFoo2el2>();
    sfoo22.call_f_and_return( ff2);

    char* sss = "gdg";

    std::cout<<type(sss)<<std::endl;


    std::cout<<"///////////////////////////////////"<<std::endl;
    auto argString = "1";
    auto argString2 = "2";
    auto argInt1 = 2;
    auto argInt2 = 4;
    // auto result = add(argString,argInt1);
    
    // std::cout<<result<<std::endl;

    auto result2 = add(argInt1,argInt2);
    std::cout<<result2<<std::endl;

    //auto result3 = add(argString,argString2);
    return 0;


}