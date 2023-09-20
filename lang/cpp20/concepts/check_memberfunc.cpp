#include <iostream>
#include <concepts>

template<typename T>
concept LanguagePolicyConcept = requires(T a)
{
    {a.message()} -> std::same_as<std::string>;
};

/*
 *   if std::string message() is not defined, it will throw errors.
 */
class LanguagePolicyNothing
{
public:    
};

class LanguagePolicyEnglish
{
public:
    std::string message()
    {
        return "Hello World";
    }
};

template<LanguagePolicyConcept T>
class A
{
    T obj;
    public:
    void print()
    {
        std::cout << obj.message() << std::endl; 
    }
};

int main()
{
    A<LanguagePolicyEnglish> a;

    a.print();

    ///A<LanguagePolicyNothing> b; //compilation error
    return 0;
}