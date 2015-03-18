#ifndef _SUFFIX_ARRAY_H
#define _SUFFIX_ARRAY_H
#define F cout << __PRETTY_FUNCTION__ << endl
#include<algorithm>
#include<cstring>
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>


using namespace std;
template<class T>
struct comp_func
{
    bool operator()(const T l,const T r)
    {

        return strcmp((l).addr_,(r).addr_) < 0;

    }
};
template<class T =char>
class SuffixArray
{


    public:
        struct A
        {
            T *addr_;
            int str_;
            A(T *a,int str):addr_(a),str_(str){}
            A(const A &aa):addr_(aa.addr_),str_(aa.str_){}
        };

        vector<A> data_;
        vector<int> types_;
        vector<bool> typesChecked;
        int len_;
        T *operator[](int i)
        {
            if(i<0 || i>len_)
                throw std::out_of_range("Out of range error\n");
            return data_[i].addr_;
        }
        //to support GSA
        SuffixArray(vector<char *> &vStr):len_(0)
    {
        unsigned int k = 0;
        for(int i =0;i<vStr.size();++i)
        {
            types_.push_back(i);
            typesChecked.push_back(false);
            for(size_t j=0;j<(strlen(vStr[i])-1);++j)
            {
                A aa(&vStr[i][j],i);
                data_.push_back(aa);
            }
        }
        len_ = data_.size();
        std::sort(data_.begin(),data_.end(),comp_func<const A &>());
    }
        ~SuffixArray()
        {

            //delete [] data_;
        }
        void Print()
        {
            cout << "SUFFIX ARRAY===\n";
            for(int i =0;i<len_;++i)
            {
                cout << data_[i].addr_ << endl;
            }
            cout << "END===\n";

        }

    // p -pattern
    // 
   int binarySearch(T *p)
   {
       int low = 0,high = len_;
       int mid = 0;
       int m  = strlen(p);
       cout << "pattenr:" << p << endl;
       cout << "m:" << m << endl;
       bool found = false;
       cout << "len_ " << len_ << endl;
       while(low<=high && !found)
       {
           cout << "low:" << low << endl;
           cout << "high:" << high << endl;
           mid = (low+high)/2;
           cout << "mid: " << mid << endl;
           cout << "SA:" << data_[mid].addr_ << endl;
           cout << "LCP:" << LCP(p,data_[mid].addr_) << endl;
           if(LCP(p, data_[mid].addr_)  == m)
           {
               cout << "found\n";
               found = true;
               break;
           }
           else if(strcmp(p,data_[mid].addr_) < 0)
               high = mid - 1;
           else
               low = mid+1;
              // high = mid + 1;
       }
       return low;

   }

};


#endif
