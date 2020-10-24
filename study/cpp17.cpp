#include <iostream>
#include<memory>
#include<typeinfo>

class Foo
{
    public:
    const std::string name = "min";
};

Foo *get_foo()
{
    return nullptr;
}

template<int n>
struct Foo2{
    enum{
        value = n
    };

};


template <int N, int D = 1>
struct Ratio {
  typedef Ratio<N, D> type;
  static const int num = N;  // 분자
  static const int den = D;  // 분모
};

struct NormalRatio {
    int num;  // 분자
    int den;  // 분모
};

class People{};


template<typename T>
constexpr auto isInt(T t){
    if constexpr(std::is_same<T, int>::value){
        
        return t;
    }else if constexpr(std::is_same<T, People>>::value){
        return "People임";
    }else{
        return"babo";
    }
}

template<typename T>
void printT(T t){
    std::cout<<t<<std::endl;
}

//  template<typename... Args>
//  void printArgs(Args)

int main()
{
    

    // {
    //     if(Foo *ptr = get_foo(); ptr != nullptr)
    //         std::cout<<ptr->name<<std::endl;
    //     else{
    //         std::cout<<"nullptr"<<std::endl;
    //     }

    //     std::cout<<Foo2<2>::value<<std::endl;
    // }
    // Ratio<2,3> ratio;
    // typedef Ratio<3,4> rat;
    // typedef NormalRatio nRat;
    

    // std::cout<<ratio.num<<"/"<<ratio.den<<std::endl;
    // std::cout<<rat::num<<"/"<<rat::den<<std::endl;
    // int t= 10;
    // std::cout<<isInt(t)<<std::endl;;
    // std::cout<<isInt(20)<<std::endl;;
    // std::cout<<isInt("hello")<<std::endl;;




}