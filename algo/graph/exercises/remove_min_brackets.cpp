/*
 *
 * Given a string of parenthesis and alphabtes, digits (a(0)) or
 * (#($)*), remove the minimum number of brackets to get a balanced bracket
 * sequence i.e. (()()) or ((())())
 *
 * input: (a)())()
 * output: [(a)()(), (a())()]
 * */

#include <iostream>
#include <vector>
#include <set>

bool isValid(const std::string &input)
{
   int cnt = 0;

   for (auto x: input)
     {
        if (x == '(') cnt++;
        else if (x == ')') cnt--;
        //to handle ")("
        if (cnt < 0) return false;
     }

   return cnt == 0;
}

void getPossibleComb(const std::string &input, std::vector<std::string> &out, char deleteChar)
{
   bool isPossible = false;
   for (int i = 0; i < input.size(); ++i)
     {
        if (input[i] == deleteChar)
          {
             std::string tmp = input;
             tmp.erase(tmp.begin() + i);
             out.push_back(tmp);
          }
     }
}

void getAnswer(const std::string &input, std::set<std::string> &ans)
{
   std::cout << "input: ";
   std::cout << input << std::endl;
   //find diff between ) and (
   int br1_count = 0, br2_count = 0;
   for (auto &x: input)
     {
        if (x == '(') br1_count++;
        else if (x == ')') br2_count++;
     }

   int diff = std::abs(br1_count - br2_count);
   char deleteChar = br1_count > br2_count ? '(': ')';

   for (int i = 0; i < diff; ++i)
     {
        std::vector<std::string> level;

        getPossibleComb(input, level, deleteChar);

        for (std::string s: level)
          {
             if (isValid(s)) ans.insert(s);
          }
     }
   if (diff == 0 && isValid(input))
     ans.insert(input);
}

int main()
{
   std::set<std::string> ans;
   getAnswer("(a)())()", ans);

   std::cout << "[";
   for (auto &x: ans)
     std::cout << x << ", ";
   std::cout << "]";
   std::cout << std::endl;

   return 0;
}
