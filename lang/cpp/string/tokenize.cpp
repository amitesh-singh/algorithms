#include <iostream>
#include <string>
#include <vector>

void tokenize(const std::string &str, std::string delim, std::vector<std::string> &ans)
{
    size_t start = 0;
    size_t end = 0;
    std::string s = str;
    
    end = s.find(delim);    
    int offset = delim.size();

    while (end != str.npos)
    {
        ans.push_back(s.substr(start, end - start));
        start = end + offset;

        end = s.find(delim, start);
    }

    ans.push_back(s.substr(start));
}

int main()
{
    std::vector<std::string> ans;
    tokenize("dog:cat:monkey", ":", ans);

    for (auto &x: ans)
        std::cout << x << "->";
    std::cout << std::endl;

    return 0;
}