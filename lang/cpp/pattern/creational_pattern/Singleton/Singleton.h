template<typename T>
class Singleton
{
    public:
    static Singleton<T> *Instance();
    protected:
    Singleton();
    private:
    static Singleton<T> *_instance;
    T _value;
};
