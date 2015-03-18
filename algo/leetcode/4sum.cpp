/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique
quadruplets in the array which gives the sum of target.

*/



class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> quad(4);
        vector<vector<int> > quads;
        std::sort(num.begin(),num.end());
        int n = num.size();
        int a,b,c,d;
        int j,k,l;
        int p;
        for(int i =0;i<n-3;i++)
        {
            quad.clear();
            a = num[i];
            for(p = i+1;p<n-2;p++)
            {
                b=num[p];
                k = p+1;
                l = n-1;
                while(k<l)
                {
                    c = num[k];
                    d = num[l];
                    if(b+c+d == target - a)
                    {
                        quad.push_back(a);
                        quad.push_back(b);
                        quad.push_back(c);
                        quad.push_back(d);
                        quads.push_back(quad);
                        k++;
                        l--;
                        quad.clear();
                        
                    }
                    else if(b+c+d > target -a)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                        
                    }
                }
            }
            
            
        }
        return quads;
    }
};
