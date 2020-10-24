
namespace min
{
    class SharedResource{
        template<typename T>
        T t;

        template<typename T>
        T getT(){
            return t;
        }

        public:
        template<typename T>
        SharedResource(T t){
            this->t = t;
        }
    };
    

}