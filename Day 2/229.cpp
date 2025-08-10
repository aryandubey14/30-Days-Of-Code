#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> majorityElement2(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> answers;

        if (n==1)
        {
            return nums;
        }
        if (n==2)
        {
            if (nums[0]==nums[1])
            {
                answers.push_back(nums[0]);
                return answers;
            }
            else
            {
                return nums;
            }
        }
        if (n==3)
        {
            for (int i = 0; i < 3; i++)
            {
                int CountOfNum=count(nums.begin(),nums.end(),nums[i]);
                if (CountOfNum>1)
                {
                    answers.push_back(nums[i]);
                    break;
                }
            }
            return answers;
        }
        
        int Frequency=1;

        sort(nums.begin(),nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i]==nums[i-1])
            {
                Frequency++;
            }
            else
            {
                Frequency=1;
            }

            if (Frequency>(n/3))
            {
                if (find(answers.begin(), answers.end(), nums[i]) == answers.end())
                {
                    answers.push_back(nums[i]);
                }
            }
        }
        
        return answers;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,2,3};
    //vector<int> nums2 = {1,2};

    nums=s.majorityElement2(nums);
    //nums2=s.majorityElement2(nums2);

    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    // for(int i=0; i<nums2.size(); i++)
    // {
    //     cout<<nums2[i]<<" ";
    // }
}