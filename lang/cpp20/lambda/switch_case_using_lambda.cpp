#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

enum values
{
   FIRST,
   SECOND,
   THIRD,
   LAST
};

int main()
{
   ///lambda fucntion signifies a switch case statement
   constexpr auto switch_case = []<typename Key>(const Key &key, const std::vector<std::pair<Key, std::function<bool()>>> &pairs) constexpr ->bool {
        std::unordered_map<Key, std::function<bool()>> dict;
        for (const auto &entry: pairs) {
             dict.insert(entry);
        }

        const auto it = dict.find(key);
        if (it != dict.end()) {
             return it->second();
        }
        throw std::runtime_error("No matching case found");
   };


   constexpr auto switch_case2 = []<typename Key>(const Key &key, const std::unordered_map<Key, std::function<bool()>> &cases) constexpr -> bool {
        const auto it = cases.find(key);
        if (it != cases.end()) {
             return it->second();
        }

        throw std::runtime_error("No matching case found");
   };

   while (1) {
        int input;
        std::cout << "Enter input: ";
        std::cin >> input;
        bool ret = switch_case(static_cast<values>(input), {
                                    {
                                    values::FIRST, [&]() {
                                        std::cout << "First: \n";
                                        return true;
                                        }
                                    }
                               ,
                               {
                                    values::SECOND, [&]() {
                                        std::cout << "Second: \n";
                                        return true;
                                        }
                               }
                               });

        bool ret2 = switch_case2(static_cast<values>(input), {
                                 {
                                    values::FIRST, []() {
                                        std::cout << "First from 2nd \n";
                                        return true;
                                    }
                                 },
                                 {
                                    values::SECOND, []() {
                                        std::cout << "Second from 2nd: \n";
                                        return true;
                                    }
                                 },
                                 });

   };
   return 0;
}
