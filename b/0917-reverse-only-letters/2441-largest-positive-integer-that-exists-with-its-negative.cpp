class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, bool> m;
        int res = -1;
        for (int n : nums) {
            if (m[-n]) res = max(res, abs(n));
            m[n] = true;
        }
        return res;
    }
};