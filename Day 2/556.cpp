#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    /*int nextGreaterElement(int n) 
    {
        vector<int> digits;

        if (n<=10) return -1;
        
        while (n > 0) 
        {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());
        int size=digits.size();

        int numberOfSwaps=0;
        for (int i = size-2; i >=0 ; i--)
        {
            if (digits[i]<digits[i+1])
            {
                swap(digits[i],digits[i+1]);
                numberOfSwaps++;
                break;
            }
        }
        if(numberOfSwaps==0) return -1;
        
        int newNum=0;
        for (int i = 0; i < size; i++)
        {
            newNum = newNum * 10 + digits[i];
        }

        return newNum;
    }*/
   int nextGreaterElement(int n) 
   {
        vector<int> digits;
        int temp = n;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        reverse(digits.begin(), digits.end());

        int size = digits.size();
        if (size <= 1)
            return -1; // single digit → no next greater

        // Step 1: Find first decreasing digit from right
        int i = size - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) {
            i--;
        }
        if (i < 0)
            return -1; // already largest permutation

        // Step 2: Find smallest digit to right of i greater than digits[i]
        int j = size - 1;
        while (j > i && digits[j] <= digits[i]) {
            j--;
        }

        // Step 3: Swap
        swap(digits[i], digits[j]);

        // Step 4: Sort digits after i
        reverse(digits.begin() + i + 1, digits.end());

        // Step 5: Convert back to int with overflow check
        long long newNum = 0;
        for (int k = 0; k < size; k++) {
            newNum = newNum * 10 + digits[k];
            if (newNum > INT_MAX)
                return -1; // overflow
        }

        return (int)newNum;
    }
};

int main()
{
    Solution s;
    int num = 230241;

    cout<<s.nextGreaterElement(num);
}