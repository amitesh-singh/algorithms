#include <iostream>

template<class T>
struct node
{
    T data;
    node<T> *next;
 
    node(T &&data) : data(data), next(nullptr) {} 
};

template<class T>
class persistent_stack
{
    enum class op
    {
        PUSH,
        POP
    };
    node<T> *top = nullptr;
    node<T> *prev = nullptr;
    public:
    persistent_stack(node<T> *t = nullptr, op op_type = op::POP)
    {
        if (this->top != top)
        {
            if (op_type == op::PUSH)
            {
                t->next = top;
                prev = top;
                top = t;
            }
            else
            {
                top = prev;
                if (prev)
                    prev = prev->next;
            }
        }
    }

    //returns the current top
    persistent_stack<T> *push(T val)
    {
        return new persistent_stack(new node(val), op::PUSH);
    }

    //return the current top
    persistent_stack<T> *pop()
    {
        return new persistent_stack();
    }
};
int main()
{
    return 0;
}