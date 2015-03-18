#include<iostream>
#include<stdexcept>

using namespace std;
#define MAIN

//use this DS in case of cyclic string or patterns
template<class T>
class CyclicBuffer
{
    int tail_;
    int head_;
    int size_;
    T *data_;
    public:
    CyclicBuffer(int size=10):tail_(0),head_(0),size_(size),data_(new T[size_]){}
    ~CyclicBuffer(){ delete [] data_;}

    void push_back(T t)
    {
        if(tail_ == size_)
            tail_ =head_;

        data_[tail_++] = t;
    }
    T &operator[] (int index)
    {

	    if(index <0)
		    throw std::out_of_range("index can not be negative");
	    //cout << "index-size" << index%size_ << endl;
	    return data_[index%size_];
	    //else
         //   throw std::out_of_range("out of range");
    }

};

#ifdef MAIN
int main()
{
    CyclicBuffer<int> cb(3);
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    cout << cb[0] << endl; // =1
    cout << cb[1] << endl; // =2
    cout << cb[2] << endl; // =3
    cout << cb[10] << endl; // =3
    cb.push_back(4);

    cout << "After push\n";
    cout << cb[0] << endl; //=4
    cout << cb[1] << endl; //=2
    cout << cb[2] << endl; //=3

    return 0;
}
#endif
