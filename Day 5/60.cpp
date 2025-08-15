#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> fact(n, 1);
        
        // Precompute factorials
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        
        // Prepare list of numbers
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        
        // Convert k to zero-based index
        k -= 1;
        
        string result = "";
        
        for (int i = n; i >= 1; i--) {
            int index = k / fact[i - 1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= fact[i - 1];
        }
        
        return result;
    }
};

int main() {
    Solution s;
    int n = 3, k = 4;
    cout << s.getPermutation(n, k) << endl; // Output: "231"
}