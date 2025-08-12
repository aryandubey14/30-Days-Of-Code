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
        
        // Fill MaxFromLeft
        MaxFromLeft[0] = arr[0];
        for (int i = 1; i < n; i++) {
            MaxFromLeft[i] = max(MaxFromLeft[i - 1], arr[i]);
        }

        // Fill MinFromRight
        MinFromRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            MinFromRight[i] = min(MinFromRight[i + 1], arr[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            if (MaxFromLeft[i] <= MinFromRight[i + 1]) {
                chunks++;
            }
        }

        return chunks;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2,1,3,4,4};

    cout<<s.maxChunksToSorted(arr);
}