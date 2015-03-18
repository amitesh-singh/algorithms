/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return
the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //we are trying for target +1
        int n = num.size();
        std::sort(num.begin(),num.end());
        int j,k;
        int a,b,c;
        int min_diff = INT_MAX;
        int sum = 0;
        int diff = 0;
        int sol = 0;
        for(int i =0;i<n-2;i++)
        {
            a = num[i];
            j = i+1;
            k = n-1;
            while(j<k)
            {
                
                b = num[j];
                c = num[k];
                sum = a+b+c;
                
                if (sum == target)
                    return sum;
                else if(sum > target)
                {
                    diff = sum- target;
                    if(diff < min_diff)
                    {
                        min_diff = diff;
                        sol = sum;    
                    }
                    k--;
                
                }
                else if(sum < target)
                {
                    diff = target - sum;
                    if(diff < min_diff)
                    {
                        min_diff = diff;
                        sol = sum;
                    }
                    j++;
                    
                }
                
            }
            
        }
        return sol;
        
    }
};
