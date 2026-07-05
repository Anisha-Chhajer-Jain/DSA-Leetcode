class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;
        int pairs = 0, left = 0;
        for (auto& p : m) {
            pairs += p.second / 2;
            left += p.second % 2;
        }
        return {pairs, left};
    }
};