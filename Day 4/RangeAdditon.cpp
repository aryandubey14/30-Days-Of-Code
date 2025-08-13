#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    vector<int> ModifyArray(int startIdx,int endIdx, int increment,vector<int>& nums) 
    {
        for (int i = startIdx; i <= endIdx; i++)
        {
            nums[i]+=increment;
        }
        return nums;
    }

    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) 
    {
        // Write your code here
        vector<int> nums(length,0);

        for (int i = 0; i < updates.size(); i++)
        {
            nums=ModifyArray(updates[i][0], updates[i][1],updates[i][2],nums);
        }
        return nums;
    }
};

int main()
{
    int length = 5;
    vector<vector<int>> updates = {{1,3,2},{2,4,3},{0,2,-2}};
    Solution s;

    vector<int> output=s.getModifiedArray(length,updates);

    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
}