#include <mutex>
#include <memory>
namespace min
{

    template <typename T>
    class SharedResource
    {

    public:
        class LockResource;
        SharedResource(const T &t) : _resource(t) {}
        SharedResource(const SharedResource &sr){
            std::cout<<"copy constructor"<<std::endl;
        }
        SharedResource()
        {
            T createResource;
            this->_resource = createResource;
        }
        LockResource &&GetWithLock()
        {
            //std::cout<<&_resource<<std::endl;

            return std::move(LockResource(*this));
            //return LockResource(_resource);
        }
        ~SharedResource(){}

        class LockResource
        {
        public:

            LockResource(SharedResource<T> &sr) : _sr(sr){
                std::cout<<"lock "<<&_sr._mutex<<": "<<_sr._resource<<std::endl;
                _sr._mutex.lock();
            }
            ~LockResource()
            {
                std::cout<<"unlock "<<&_sr._mutex<<": "<<_sr._resource<<std::endl;
                _sr._mutex.unlock();
            }
            template<typename IN>
            T operator=(IN in){
                std::cout<<"= operator"<<std::endl;
                return _sr._resource;
            }
            T &Get()
            {
                return _sr._resource;
            }

        private:
        SharedResource<T> &_sr;
       
        };

    protected:
        
        T _resource;
        std::mutex _mutex;
    };

} // namespace min