#include <iostream>
#include <functional>
#include <type_traits>

class meh
{
    public:
    void dispatch(std::function<void()> f) {
        f();
    }

    template<typename Func, typename Arg1, typename... Args>
    void dispatch(Func &&func, Arg1 &&arg1, Args&&... args)
    {
        //dispatch(std::bind(std::forward<Func>(func), std::forward<Arg1>(arg1),
        // std::forward<Args>(args)...));
        dispatch([&]()->void {
            if constexpr (std::is_member_function_pointer<Func>::value and !std::is_pointer<Arg1>::value)
                (std::forward<Arg1>(arg1).*std::forward<Func>(func))(std::forward<Args>(args)...);
           else if constexpr (!std::is_member_function_pointer<Func>::value) 
                std::forward<Func>(func)(std::forward<Arg1>(arg1), std::forward<Args>(args)...);
            else if constexpr (std::is_member_function_pointer<Func>::value and std::is_pointer<Arg1>::value)
                (std::forward<Arg1>(arg1)->*std::forward<Func>(func))(std::forward<Args>(args)...);
        });
        
    }
};
class A
{
    public:
    void f() {}
    void f2(int) { std::cout << "int\n";}
};

void callme()
{
    std::cout << "callme \n";
}

void callme2(int )
{
    std::cout << "callme int\n";
}

int main()
{
    meh meh;
    meh.dispatch([]()->void {});
    A aa;
    meh.dispatch(&A::f, (aa));
    //meh.dispatch(&A::f, std::ref(aa)); <<-- won't work
    meh.dispatch(&A::f, &aa);

    std::cout << std::is_pointer<A *&>::value << std::endl;
    //meh.dispatch(&A::f2, std::ref(aa), 2); //<< - with ref did not work
    meh.dispatch(callme);
    meh.dispatch(callme2, 10);
    return 0;
}