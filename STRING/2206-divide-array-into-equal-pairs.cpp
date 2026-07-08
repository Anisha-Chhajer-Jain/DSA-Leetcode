class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;
        for (auto& p : m) {
            if (p.second % 2 != 0) return false;
        }
        return true;
    }
};