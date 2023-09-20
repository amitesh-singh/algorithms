#include <iostream>
#include <fstream>

template<typename OutputPolicy>
class message
{
public:
    void write(const std::string &msg)
    {
        out_policy_.print(msg);
    }

private:
   /* https://en.cppreference.com/w/cpp/language/attributes/no_unique_address 
    * Empty class optimization
    */
    [[no_unique_address]] OutputPolicy out_policy_;
};

class write_to_cout
{
public:
    void print(const std::string &msg)
    {
        std::cout << msg << '\n';
    }
};

class write_to_tmp
{
    static const constexpr auto FILE { "/tmp/tmp.txt" };
public:
    write_to_tmp()
    {
        out_.open(FILE);
    }

    void print(const std::string &msg)
    {
        out_ << msg << '\n';
    }

private:
    std::ofstream out_;
};

int main()
{
    message<write_to_cout> msg;
    msg.write("hey man");

    message<write_to_tmp> msg2;
    msg2.write("hey man2");

    return 0;
}