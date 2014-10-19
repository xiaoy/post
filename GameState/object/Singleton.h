#ifndef __SINGLETON__
#define __SINGLETON__
template<class T>
class Singleton{
    private:
        static T* instance_;
    protected:
        Singleton(){};
        ~Singleton(){};
    public:
        static T* Instance(){
        if(instance_ == nullptr){
            instance_ = new T();
        }
        return instance_;
    }
};

template<class T> T* Singleton<T>::instance_ = nullptr;
#endif
