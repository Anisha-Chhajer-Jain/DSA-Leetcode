class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Traverse map
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            int count = it->second;
            int val = it->first;

            for (int i = 0; i < count; i++) {
                if (res.size() <= i) {
                    res.push_back({});
                }
                res[i].push_back(val);
            }
        }

        return res;
    }
};