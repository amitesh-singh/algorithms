#include <list>
#include <iostream>

namespace nonstd
{
    //if 
    template <class T>
    class stack
    {
        std::list<T> _data;
        public:
        stack() = default;

        T pop()
        {
            int d = _data.back();
            _data.pop_back();

            return d;
        }
        
        void push(T &d)
        {
            _data.push_back(d);
        }
        
        T top()
        {
            return _data.back();
        }

        int size() const
        {
            return _data.size();
        }
    };
}

int main()
{
    nonstd::stack<int> st;
    
    for (int i = 0; i < 10; ++i)
        st.push(i);

    int size = st.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << st.top() << ", ";
        st.pop();
    }

    std::cout << "\n";

    return 0;
}