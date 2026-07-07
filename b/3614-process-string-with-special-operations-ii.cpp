class Solution {
public:
    char processStr(string s, long long k) {
       int n = s.length();
        vector<long long> lengths(n);
        long long curr_len = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (islower(ch)) {
                curr_len++;
            } else if (ch == '*') {
                if (curr_len > 0) curr_len--;
            } else if (ch == '#') {
                curr_len *= 2;
            } else if (ch == '%') {
            }
            lengths[i] = curr_len;
        }
        if (k < 0 || k >= curr_len) {
            return '.';
        }
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long len_before = (i == 0) ? 0 : lengths[i - 1];

            if (ch == '%') {
                k = len_before - 1 - k;
            } 
            else if (ch == '#') {
                k %= len_before;
            } 
            else if (ch == '*') {
            } 
            else if (islower(ch)) {
                if (k == len_before) {
                    return ch;
                }
            }
        }

        return '.';
    }
};