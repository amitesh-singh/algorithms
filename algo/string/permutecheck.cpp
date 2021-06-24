#include <iostream>
#include <unordered_map>

using String = std::string;
//Given two strings, write a method to decide if one is a permutation of the other.
bool isPermuteSame(const String &s1, const String &s2)
{
    if (s1.size() != s2.size()) return false;

    std::unordered_map<char, int> m;
    for (auto &c: s1)
    {
        if (m.find(c) == m.end())
            m[c] = 1;
        else
            m[c]++;
    }

    for (auto &c: s2)
    {
        if (m.find(c) == m.end())
            return false;
        else
        {
            if (m[c] > 0)
                m[c]--;
            else
                return false;
        }
    }

    return true;
}

bool isPermuteSame2(const std::string &str1, const std::string &str2)
{
    if (str1.size() != str2.size()) return false;

    int res = 0;

    for (int i = 0; i < str1.size(); ++i)
    {
        res ^= str1[i] ^ str2[i];
    }

    return (res == 0) ? true: false;
}
int main()
{
    // abcc ccba
    std::cout << isPermuteSame("abcc", "ccba") << std::endl;
    std::cout << isPermuteSame2("abcc", "ccba") << std::endl;
    
    return 0;
}
