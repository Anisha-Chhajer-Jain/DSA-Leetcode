class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxFreq = 0, res = -1;
        for (int n : nums) {
            if (n % 2 == 0) {
                m[n]++;
                if (m[n] > maxFreq || (m[n] == maxFreq && n < res)) {
                    maxFreq = m[n];
                    res = n;
                }
            }
        }
        return res;
    }
};