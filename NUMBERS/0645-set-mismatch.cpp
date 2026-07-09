class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector <int> mp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        vector <int> ans(2, 0);
        for (int i = 1; i < n + 1; i++) {
            if (mp[i] == 0) {
                ans[1] = i;
            } else if (mp[i] == 2) {
                ans[0] = i;
            }
            if (ans[0] && ans[1]) {
                break;
            }
        }
        return ans;
    }
};