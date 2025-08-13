#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int bound) {
        int ans = 0, count = 0;
        for (int num : nums) {
            if (num <= bound) {
                count++;
                ans += count;
            } else {
                count = 0;
            }
        }
        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {73,55,36,5,55,14,9,7,72,52};
    // int left = 32;
    // int right = 69;

    vector<int> arr2 = {2,9,2,5,6};
    int left = 2;
    int right = 8;

    cout<<s.numSubarrayBoundedMax(arr2, left, right);
}