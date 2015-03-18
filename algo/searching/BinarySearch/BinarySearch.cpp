#include<iostream>
#include<vector>
using namespace std;

template<typename T1,typename T2>
int BinarySearch(T2 &arr,int arrSize,T1 &key)
{
	int lo =0,mid,hi = arrSize - 1;
	while(lo <= hi)
	{
		mid = (lo + hi)/2;
		if(key<arr[mid])
			hi = mid - 1;
		else if(key > arr[mid])
			lo = mid + 1;
		else
			return mid;
	}

	return -1;
}
int main()
{
	vector<int> v;
	v.push_back(100);
	v.push_back(132);
	v.push_back(123);
	v.push_back(344);
	int arrsize = v.size();
	int findme = 132;
	int res = BinarySearch<int,vector<int> >(v,arrsize,findme);
	cout << v[res] << endl;

}
