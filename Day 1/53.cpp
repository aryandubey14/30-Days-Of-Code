#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        int RunningSum=0;
        int MaxSum=INT32_MIN;

        for (int i = 0; i < n; i++)
        {
            RunningSum+=nums[i];
            MaxSum=max(RunningSum,MaxSum);
            if (RunningSum<0) RunningSum=0;
        }
        
        return MaxSum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    //s.rotate(nums, 3);
    int sum = s.maxSubArray(nums);
    
    cout << sum << endl;
}