#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<limits.h>
using namespace std;

class Solution {
public:
    bool findPair(vector<int> &arr, int x) 
    {
        int n= arr.size();

        unordered_map<int,bool> map;

        if (n<2) return false;

        for (int i = 0; i < n; i++)
        {
            if (map.find(arr[i] - x)!=map.end() || map.find(arr[i] + x)!=map.end())
            {
                return true;
            }
            else
            {
                map[arr[i]]=true;
            }        
        }
        
        return false;
    }
};

int main()
{
    vector<int> arr= {8,7,2,9,10,3};
    int x = 9;
    Solution s;

    cout<<boolalpha;
    cout<<endl;
    cout<<s.findPair(arr,x);
    cout<<endl;
}