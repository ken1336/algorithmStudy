#include<iostream>
#include <utility>



class Foo{

    int thing;
    public:
    
    Foo(int input  = 0) : thing(input){} 
    int getThing(){
        return thing;
    }
    static int getInt(){
        return 1;
    }
};

int main(int argc, char** argv){

    Foo foo{};
    Foo foo2(1);

    std::cout<<foo.getThing()<<std::endl;
    std::cout<<foo2.getThing()<<std::endl;
    auto test = Foo::getInt();
    return 0;

}