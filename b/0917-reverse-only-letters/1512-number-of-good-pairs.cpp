class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m; 
        int res = 0;
        for (int n : nums) res += m[n]++;
        return res;
    }
};