#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();

        if(k<0 || n==0) return;

        if (k>n) k=k%n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};

    s.rotate(nums, 3);
    
    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}