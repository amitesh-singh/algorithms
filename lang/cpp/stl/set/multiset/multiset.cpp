#include <set> //this has multiset defined 
#include <iostream>

void print(auto &s)
{
    for (auto &x:s)
        std::cout << x << ", ";
    std::cout << std::endl;
}

//multiset can have same elements.
int main()
{
    {
        //ascending order
        std::multiset<int> s;
        s.insert(100);
        s.insert(100);
        s.insert(1);
        s.insert(1);
        print(s);

        auto itr = s.find(100);
        std::cout << "occurrence of 100: " << s.count(100) << "\n";

        std::cout << "found " << *itr << std::endl;
        s.erase(itr);
        print(s);

        int c = s.count(1);

        std::cout << "occurrence of 1: " << c << std::endl;
    }

    {
        std::cout << "descending\n";
        //descending order; also std::multiset<int, std::greater<>> s;
        std::multiset<int, std::greater<int> > s;
        s.insert(100);
        s.insert(100);
        s.insert(1);
        s.insert(1);
        std::cout << "size = " << s.size() << std::endl;
        print(s);
        std::cout << "value 1 reps in the set: " << s.count(1) << std::endl;

        std::cout << "deleting 100:\n"; //it will delete all the 100s
        s.erase(100);
        print(s);

        

        //lets find all 1s, using equal_range, which returns std::pair
        auto range = s.equal_range(1);
        if (range.first == range.second) {
            //only single entry
        } else {
            for (auto it = range.first; it != range.second; ++it) {
                std::cout << *it << '\n';
            }
        }

        s.clear();
        s.empty() ? std::cout << "multiset is empty\n" : std::cout << "multiset is not empty\n";
    
    }

    return 0;
}
