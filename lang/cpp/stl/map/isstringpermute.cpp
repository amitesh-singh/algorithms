#include<iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using String =  std::string;

bool ispermute(const String &s1, const String &s2)
{
    if (s1.size() != s2.size()) return false;

    std::unordered_map<char, int> m;
    for (auto &c: s1)
    {
        auto itr = m.find(c);
        //first time entry
        if (itr == m.end())
        {
            m[c] = 1;
        }
        else
        {
            m[c]++;
        }
    }

    for (auto &c: s2)
    {
        auto itr = m.find(c);
        if (itr == m.end()) return false;
        else
        {
            if (m[c] > 0)
                m[c]--;
            else
            {
                return false;
            }
        }
    }
    return true;

}

int main()
{
    //check if two strings are permutation of each other
    //e.g. abcc accb
    std::cout << ispermute("abcc", "accb") << std::endl;
    std::cout << ispermute("abccd", "abddc") << std::endl;
    return 0;
}