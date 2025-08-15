#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<limits.h>
using namespace std;

class Solution {
public:
    bool myNextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int i = n - 2;

        // Step 1: find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i < 0) return false; // no next permutation

        // Step 2: find just larger element than nums[i] from right
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);

        // Step 3: reverse right part
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }

    vector<vector<int>> permute(vector<int> nums) 
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end()); // start with smallest
        result.push_back(nums);

        while (myNextPermutation(nums)) 
        {
            result.push_back(nums);
        }
        return result;
    }

    vector<vector<int>> permuteOptimized(vector<int>& nums) 
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end()); // start with smallest order
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return result;
    }
};

int main()
{
    vector<int> arr= {1,2,3};

    vector<vector<int>> result = Solution().permute(arr);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
}