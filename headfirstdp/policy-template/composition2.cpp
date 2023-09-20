/*
In this example, we implement two policies
*/

#include <iostream>

template<typename OutputPolicy, typename LanguagePolicy>
class message
{
public:
    void write()
    {
        out_.print(lang_.message());
    }
private:
   [[no_unique_address]] OutputPolicy out_;
   [[no_unique_address]] LanguagePolicy lang_;
};

struct LanguagePolicy
{
    virtual std::string message() = 0;
};

struct LanguagePolicyEnglish: public LanguagePolicy
{
    std::string message() override
    {
        return "Hello World!";
    }
};

struct LanguagePolicyHindi: public LanguagePolicy
{
    std::string message() override
    {
        return "Namskar Duniya!";
    }
};

struct OutputPolicy
{
    void print(const std::string &msg)
    {
        std::cout << msg << '\n';
    }
};

int main()
{
    OutputPolicy out;
    LanguagePolicyHindi hindi;

    message<OutputPolicy, LanguagePolicyHindi> msg;
    msg.write();
    
    return 0;
}