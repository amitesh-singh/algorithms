#ifndef _BINARY_SEARCH_H
#define _BINARY_SEARCH_H

#include<iostream>

template<class arr,class function1,class function2,class key,class out>
out BinarySearch(arr ar,int size,key &k,function1 lesser1,function2 greater1)
{
    int low =0,mid,hi = size-1;
    while(low<=hi)
    {
        mid = (low+hi)/2;
        bool yo1 = lesser1(k,ar,mid);
        if(yo1)
        {
            hi = mid -1;

        }
        else if(greater1(k,ar,mid) == true)
            low = mid+1;
        else
        return mid;

    }


}

#endif
