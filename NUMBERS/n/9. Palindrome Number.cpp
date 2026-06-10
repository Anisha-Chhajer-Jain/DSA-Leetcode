#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are not palindrome
        if (x < 0) {
            return false;
        }

        int original = x;
        int rev = 0;

        // Reverse the number
        while (x > 0) {

            int digit = x % 10;

            rev = rev * 10 + digit;

            x = x / 10;
        }

        // Check original and reversed number
        return original == rev;
    }
};

int main() {

    Solution s;

    int x = 121;

    if (s.isPalindrome(x)) {
        cout << "Palindrome";
    }
    else {
        cout << "Not Palindrome";
    }

    return 0;
}