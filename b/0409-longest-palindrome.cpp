class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        int ans = 0; bool odd = false;
        for (auto& p : m) {
            ans += (p.second / 2) * 2;
            if (p.second % 2 == 1) odd = true;
        }
        return ans + odd;
    }
};