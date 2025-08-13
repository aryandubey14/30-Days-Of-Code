#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) 
    {
        // Your code here
        int minPlatforms=0;
        int n=arr.size();

        int count=0;

        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());

        int a=0,d=0;

        while(a<n)
        {
            if (arr[a]<=dep[d])
            {
                count++;
                a++;
            }
            else
            {
                count--;
                d++;
            }
            
            minPlatforms=max(minPlatforms,count);
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