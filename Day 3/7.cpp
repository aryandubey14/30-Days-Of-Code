#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        long long result = 0;

        if (x > 0) {
            while (x > 0) {
                result = result * 10;
                result += (x % 10);
                x /= 10;
            }

            if(result>INT_MAX ) return 0;

            return result;
        } 
        
        else if (x < 0) 
        {
            while (x < 0) {
                result = result * 10;
                result -= (x % 10);
                x /= 10;
            }

            if(result<INT_MIN) return 0;
            
            return result * -1;
        }

        return result;
    }
};

int main()
{
    int x = -2147483648;
    Solution s;

    cout<<s.reverse(x);
}