/*
 *
 * Given a string of parenthesis and alphabtes, digits (a(0)) or
 * (#($)*), remove the minimum number of brackets to get a balanced bracket
 * sequence i.e. (()()) or ((())())
 *
 * input: (a)())()
 * output: [(a)()(), (a())()]
 * */
/*

https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
This problem requires optimum solution. 
**/
#include <iostream>
#include <vector>
#include <set>
#include <queue>

class Solution {
public:
    bool isValid(const std::string &input)
    {
        int cnt {0};
        for (auto &x: input)
        {
            if (x == '(') cnt++;
            else if (x == ')') cnt--;
            //handle )(
            if (cnt < 0) return false;
        }
        
        return cnt == 0;
    }
    
    void generatePossibleComb(const std::string &str, std::vector<std::string> &children)
    {
        char x;
        for (int i = 0; i < str.size(); ++i)
        {
            x = str[i];
            if (x == '(' or x == ')')
            {
                std::string tmp = str.substr(0, i) + str.substr(i + 1);
                children.push_back(tmp);
            }
        }
    }
    
    void getPossibleComb(const std::string &input, std::set<std::string> &ans)
    {
        std::queue<std::string> q;
        q.push(input);
        int level = 0;
        while (!q.empty())
        {
            int n = q.size();
            level++;
            //std::cout << "level =" << level << std::endl;
            for (int  i = 0; i < n; ++i)
            {
                std::string tmp = q.front();
                q.pop();
                std::vector<std::string> children;
                generatePossibleComb(tmp, children);


                //std::cout << "tmp: " << tmp << std::endl;
                //std::cout << "inside\n";
                for (auto &x: children)
                {
                    if (isValid(x))
                    {
                        ans.insert(x);
                        return;
                    }
                    else
                        q.push(x);
                }
            }
        }
    }
    
    std::string minRemoveToMakeValid(std::string s) {
        std::string res = "";
        
        std::set<std::string> ans;
        
        getPossibleComb(s, ans);
        
        if (ans.size() > 0)
        {
            auto itr = ans.end();
            itr--;
            res = *itr;
        }
        else if (isValid(s))
        {
            res = s;
        }
            
        return res;
    }
};

int main()
{
   Solution sol;
   std::string ans = sol.minRemoveToMakeValid("(a)())()");

   std::cout << ans;
   std::cout << std::endl;

   ans = sol.minRemoveToMakeValid("())()(((");
   std::cout << ans;
   std::cout << std::endl;

   ans = sol.minRemoveToMakeValid("()))((ksg(((u((()c)(");
   std::cout << ans;
   std::cout << std::endl;

   return 0;
}
