#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        int current=0;
        int LeftProduct=1;
        int RightProduct=1;

        vector<int> answer(n);

        for (int i = n-1; i >=0; --i)
        {
            answer[i]=RightProduct;
            RightProduct*=nums[i];
        }
        for (int i = 0; i< n; ++i)
        {
            answer[i]*=LeftProduct;
            LeftProduct*=nums[i];
        }

        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4};

    //s.rotate(nums, 3);
    nums = s.productExceptSelf(nums);

    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}