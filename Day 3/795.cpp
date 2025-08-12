#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    /*int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n = nums.size();
        int answer=0;

        for (int i = 0; i < n; i++)
        {
            for (int j=i; j < n; j++)
            {
                int maxNum = nums[j];
                maxNum = max(maxNum,nums[j]);

                if (maxNum >= right)
                {
                    break;
                }
                answer++;
            }
        }
        
        return answer;
    }*/
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n = nums.size();
        int answer = 0;
        int maxNum=nums[0];

        for (int i = 0; i < n; i++)
        {
            maxNum=max(maxNum,nums[i]);
            if (maxNum>=right)
            {
                break;
            }
            answer= answer+i+1;
        }
        
        return answer;
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