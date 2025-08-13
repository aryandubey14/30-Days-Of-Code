#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();

        // Place each number at its correct index if possible
        for (int i = 0; i < n; i++) 
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
             {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first missing positive
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] != i + 1) 
            {
                return i + 1;
            }
        }

        // If all numbers are in the correct place
        return n + 1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {100000, 3, 4000, 2, 15, 1, 99999};

    cout<<s.firstMissingPositive(arr);
}