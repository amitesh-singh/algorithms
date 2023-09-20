#include <iostream>
#include <concepts> //not needed


template<typename LanguagePolicy>
concept LanguagePolicyConcept = requires(LanguagePolicy a)
{
    {a.message()} -> std::convertible_to<std::string>;
};

template<typename OutputPolicy>
concept OutputPolicyConcept = requires(OutputPolicy a)
{
    {a.print(std::string("hey"))} -> std::same_as<void>;
};

template<OutputPolicyConcept OutputPolicy, typename LanguagePolicy>
requires LanguagePolicyConcept<LanguagePolicy>
class app: OutputPolicy, LanguagePolicy
{
    public:
    void write()
    {
        print(message());
    }

    using OutputPolicy::print;
    using LanguagePolicy::message;
};


class LanguagePolicyEnglish
{
    public:
    std::string message()
    {
        return "Hello World!";
    }
};

class OutputPolicyCout
{
    public:
    void print(const std::string &msg)
    {
        std::cout << msg << '\n';
    }
};
int main()
{
    app<OutputPolicyCout, LanguagePolicyEnglish> app;

    app.write();

    return 0;
}



