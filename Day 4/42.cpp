#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int MaxHeightLeft(vector<int>& height, int i) 
    {
        int LeftMax=0;
        for (int j = 0; j < i; j++)
        {
            if (height[j] > LeftMax)
            {
                LeftMax=height[j];
            }
        }
        return LeftMax;
    }

    int MaxHeightRight(vector<int>& height, int i) 
    {
        int RightMax=0;
        for (int j = i+1; j < height.size(); j++)
        {
            if (height[j] > RightMax)
            {
                RightMax=height[j];
            }
        }
        return RightMax;
    }

    int trap2(vector<int>& height) 
    {
        int n = height.size();
        int WaterTrapped=0;

        for (int i = 1; i < n-1; i++)
        {
            /*if (height[i]>currentMaxHeight)
            {
                currentMaxHeight = height[i];
            }
            else
            {
                WaterTrapped = WaterTrapped + (currentMaxHeight - height[i]);
            }*/
            int LeftMax = MaxHeightLeft(height, i);
            int RightMax = MaxHeightRight(height, i);
            int MaxWaterHeight=min(LeftMax,RightMax);

            if (height[i]<MaxWaterHeight)
            {
                WaterTrapped = WaterTrapped + (MaxWaterHeight - height[i]);
            }
        }
        
        return WaterTrapped;
    }

    int trap(vector<int>& height) 
    {
        int n = height.size();
        int WaterTrapped=0;

        vector<int> LeftMax(n,0);
        vector<int> RightMax(n,0);
        int leftMax=height[0];
        int rightMax=height[n-1];

        for (int i = 0; i < n; i++)
        {
            if (height[i]>leftMax)
            {
                leftMax=height[i];
            }

            LeftMax[i]=leftMax;
        }
        
        for (int i = n-1; i >= 0; i--)
        {
            if (height[i]>rightMax)
            {
                rightMax=height[i];
            }

            RightMax[i]=rightMax;
        }

        for (int i = 1; i < n-1; i++)
        {
            int MaxWaterHeight=min(LeftMax[i],RightMax[i]);

            if (height[i]<MaxWaterHeight)
            {
                WaterTrapped = WaterTrapped + (MaxWaterHeight - height[i]);
            }
        }
        
        return WaterTrapped;
    }
};

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;

    cout<<s.trap(height);
}