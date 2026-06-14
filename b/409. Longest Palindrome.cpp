class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        int ans = 0;
        bool odd = false;

        for (int i = 0; i < 128; i++) {
            if (freq[i] % 2 == 0) {
                ans += freq[i];
            } else {
                ans += freq[i] - 1;
                odd = true;
            }
        }

        if (odd) {
            ans++;
        }

        return ans;
    }
};