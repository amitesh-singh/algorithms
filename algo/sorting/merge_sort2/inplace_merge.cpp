#include<iostream>
#include<iterator>

using namespace std;

void shift(int A[],int pos1,int pos2)
{
    int i = pos1;
    int temp = 0;
    while(i<=pos2)
    {
        temp = A[i+1];
        A[i+1] = A[i];
        A[i+2] = temp;
        i++;

    }
}
void inplaceMerge(int A[],int p,int q,int r)
{
    int n1 = q-p + 1;
    int n2 = r-q+1;


    int k = 0;
    int i=0;
    int j = q;
    while(i<n1 && j < (n2+n1))
    {
        cout << "i:" << i << " j:" << j << endl;
        int temp = 0;
        if(A[i] <= A[j])
        {
            i++;
            j++;
        }
        else
        {
            temp = A[i];
            A[i] = A[j];
            shift(A,i+1,j);
            A[i+1] = temp;
            j++;
            i++;
        }
    }

}

int main()
{
    int A[] = {10,11,12,13,1,2,3};
    inplaceMerge(A,0,4,6);
    copy(A,A+7,ostream_iterator<int>(cout," "));
    cout << "\n";

    return 0;
}
