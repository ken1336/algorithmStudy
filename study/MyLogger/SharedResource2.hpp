#include <mutex>
#include <memory>
#include<functional>
namespace min
{

    template <typename T>
    class SharedResource2
    {

    public:

    SharedResource2(){}
    SharedResource2(const T &t) : _resource(t,deleter){
        
    }

    // operator=(){

    // }

    static constexpr auto deleter = [](){
        std::cout<<"삭제자"<<std::endl;
    };
    private:
    
  
    std::unique_ptr<T,decltype(deleter)> _resource;
    std::mutex _mutex;


    };

} // namespace min