#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        int end = n-1;
        int start=0;
        //int pos=n-1;

        vector<int> result;

        while (start<=end)
        {
            if (abs(nums[start])<abs(nums[end]))
            {
                nums[end]=nums[end]*nums[end];
                result.push_back(nums[end]);
                end--;
            }
            else
            {
                nums[start]=nums[start]*nums[start];
                result.push_back(nums[start]);
                start++;
            }
        }

        reverse(result.begin(),result.end());

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};

    //s.rotate(nums, 3);
    nums = s.sortedSquares(nums);
    
    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}