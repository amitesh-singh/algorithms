#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


set<vector<int> > three_sum(vector<int> &num)
{
    std::sort(num.begin(),num.end());
    set<vector<int> > triples;
    int n =num.size();
    int i,j,k;
    int a,b,c;
    int sum = 0;

    for(i=0;i<n-2;i++)
    {
        a = num[i];
        j = i+1;
        k = n-1;
        while(j<k)
        {
            b = num[j];
            c = num[k];
            sum = a+b+c;
            //cout << sum << endl;
            if(sum == 0)
            {
                cout << a << "," << b << "," << c << endl;
                j++;
                k--;
            }
            else
                (sum >0)?k--:j++;

        }

    }

    
    return triples;
}

int main()
{
    vector<int> num;
    int a[] = {-1,0,1,-1,2};
    num.resize(5);

    copy(a,a+ 5,num.begin());
    three_sum(num);
    


    return 0;
}
