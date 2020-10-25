#include <mutex>
#include <memory>
namespace min
{

    template <typename T>
    class SharedResource
    {
        class LockResource;

    public:
        SharedResource(T t)
        {
            _resource = t;
        }
        SharedResource()
        {
            T createResource;
            this->_resource = createResource;
        }
        LockResource GetWithLock()
        {
            return LockResource(_resource,_mutex);
        }

    private:
        T _resource;
        std::mutex _mutex;

        class LockResource
        {
        public:
            LockResource(const T &t, std::mutex &mutex)
            {
                std::lock_guard<std::mutex> _mutex(mutex);

                this->_resource = t;
            }
            ~LockResource(){
                std::cout<<"unlock"<<std::endl;
                
            }
            T Get(){
                
            }
        private:
        T _resource;


        };
    };

} // namespace min