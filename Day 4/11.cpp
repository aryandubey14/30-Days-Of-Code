#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int area=0;
        int MaxArea=0;

        int left=0;
        int right=left+1;

        while (left<n-1)
        {
            int h = min(height[left],height[right]);
            int w = right-left;
            
            area = h*w;
            
            MaxArea=max(area,MaxArea);

            if (right<n-1)
            {
                right++;
            }
            else
            {
                left++;
            }
        }

        return MaxArea;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;

    cout<<s.maxArea(height);
}