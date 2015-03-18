#ifndef _LCPArray_H
#define _LCPArray_H
#include "SuffixArray.h"

    template<class T>
int LCP(T *t1,T *t2)
{
    int n1 = strlen(t1);
    int n2 = strlen(t2);
    int ret = 0;
    //cout << "t1: " << t1 << " t2: " << t2 << endl;
    for(int i =0;i<n1 &&  i<n2;++i)
    {
        if(t1[i] == t2[i])
        {
            ret++;
            continue;
        }
        else
            break;
    }
    return ret;
}
template<class T>
class LCPArray
{
    public:
        SuffixArray<T> &sa_;
        size_t len_;
        vector<int> H_;
        LCPArray(SuffixArray<T> &s):sa_(s),len_(sa_.len_-1)
    {

    }
        //a plugin function for doing wonder?

        template<class Y>
            void makeLCP(Y func)
            {
                func(this);
            }
        ~LCPArray()
        {
            //delete [] H_;
        }

        void simpleLCS()
        {
            for(int i=1;i<sa_.len_;++i)
            {
                int lcp = LCP(sa_[i-1],sa_[i]);
                H_.push_back(lcp);

            }
        }
        void Print()
        {
            for(size_t i =0;i<H_.size();++i)
            {
                cout << "H[" << i << "]=" << H_[i] << endl;
            }
        }
        void getMax(int &longest_i,int &max)
        {
            //int max = 0;
            //int longest_i = 0;
            for(int i =0;i<H_.size();++i)
            {
                if(max < H_[i])
                {
                    max = H_[i];
                    longest_i = i;
                }
            }

        }
        //longest common sub String
        string LCS()
        {
            int max = 0;
            int longest_i = -1;
            getMax(longest_i,max);
            if(max == 0 || longest_i == -1)
                throw std::out_of_range("not found\n");
            string str(sa_[longest_i]);
            return str.substr(0,max);
        }
        /*

           string problem2()
           {

           int max = 0;
           int longest_i = -1;
           getMax(longest_i,max);

           }
         */


};

#endif
