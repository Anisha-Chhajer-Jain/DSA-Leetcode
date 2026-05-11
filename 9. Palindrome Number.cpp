class Solution {
public:
    bool isPalindrome(int x) {
       
        if (x < 0) {
            return false;
        }

        int original = x;
        int rev = 0;

        // Reverse the number
        while (x > 0) {
            int digit = x % 10;   // Take last digit
            rev = rev * 10 + digit; // Add digit to reversed number
            x = x / 10; mber
        return original == rev;
    }
};