#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        int rev = 0;

        while (x != 0) {

            int digit = x % 10;   // take last digit

            rev = rev * 10 + digit; // add digit to reverse number

            x = x / 10; // remove last digit
        }

        return rev;
    }
};

int main() {

    Solution s;

    int x = 1234;

    cout << "Reverse Number = " << s.reverse(x);

    return 0;
}