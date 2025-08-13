#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) 
    {
        // Your code here
        int minPlatforms=1;
        int n=arr.size();
        int maxDepTime=0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i]<dep[i-1])
            {
                maxDepTime=max(maxDepTime,dep[i-1]);
            }

            if (dep[i]<maxDepTime)
            {
                minPlatforms++;
            }
        }
        return minPlatforms;
    }
};

int main() 
{
    Solution s;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    
    cout << s.findPlatform(arr, dep) << endl;
}