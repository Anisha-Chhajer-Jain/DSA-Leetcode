class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> m;
        for (int i = 0; i < sorted.size(); i++) {
            if (m.find(sorted[i]) == m.end()) m[sorted[i]] = i;
        }
        vector<int> res;
        for (int n : nums) res.push_back(m[n]);
        return res;
    }
};