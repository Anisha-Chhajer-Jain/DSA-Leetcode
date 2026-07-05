class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int n : arr) {
            if (m.count(n * 2) || (n % 2 == 0 && m.count(n / 2))) return true;
            m[n]++;
        }
        return false;
    }
};