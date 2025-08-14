#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n=nums.size();

        unordered_map<int,int> map;

        for (int i = 0; i < n; i++)
        {
            int rem=target-nums[i];
            if(map.find(rem)!=map.end() && map[rem]!=i)
            {
                vector<int> ans;
                ans.push_back(map[rem]);
                ans.push_back(i);
                return ans;
            }
            else
            {
                map[nums[i]]=i;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,2,4};
    int target=6;

    nums = s.twoSum(nums,target);

    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}