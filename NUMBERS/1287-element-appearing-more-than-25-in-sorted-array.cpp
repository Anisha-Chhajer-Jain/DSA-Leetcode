class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> m;
        int threshold = arr.size() / 4;
        for (int n : arr) {
            if (++m[n] > threshold) return n;
        }
        return -1;
    }
};