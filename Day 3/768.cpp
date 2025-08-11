#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n=arr.size();
        int chunks=1;

        vector<int> MaxFromLeft(n);
        vector<int> MinFromRight(n);
        
        for (int i = 0; i < n; i++)
        {
            
        }

        return chunks;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {0,2,1,4,3,5};

    cout<<s.maxChunksToSorted(arr);
}