#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n=arr.size();
        int maxNum=arr[0];
        int chunks=0;

        for (int i = 0; i < n; i++)
        {
            maxNum=max(maxNum,arr[i]);
            if (maxNum<=i)
            {
                chunks++;
            }
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