#include <iostream>
#include <concepts>

//forcing a member function to be defined in LanguagePolicy class
//method1:
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

//method 2:

template<typename LanguagePolicy>
class B
{
    public:
    static_assert(std::is_same_v<decltype(LanguagePolicy().message()), std::string>,
                  "LanguagePolicy must provide a Message() function that returns a std::string.");
    //below will work without the need of default constructor
    // e.g. class LanguagePolicy
    //      {
    //          public: 
    //           LanguagePolicy() = delete;
    //      };
    //
    static_assert(std::is_same_v<decltype(std::declval<LanguagePolicy>().message()), std::string>,
                  "LanguagePolicy must provide a Message() function that returns a std::string.");
};

// method 3:
/*
In method 1, what if the message() class is in protected? method1 works only for 
public methods. To fix this,
You could make them public or you could hack around it like this

template <typename Policy>
struct expose_language_policy : Policy {
    using Policy::Message;
};

template <typename Policy>
concept language_policy = requires(expose_language_policy<Policy> const p) {
    { p.Message(); } -> std::convertible_to<std::string>;
};

*/
int main()
{
    A<LanguagePolicyEnglish> a;

    a.print();

    ///A<LanguagePolicyNothing> b; //compilation errors
    B<LanguagePolicyEnglish> bb;
    //B<LanguagePolicyNothing> bb2; //compilation errors

    return 0;
}