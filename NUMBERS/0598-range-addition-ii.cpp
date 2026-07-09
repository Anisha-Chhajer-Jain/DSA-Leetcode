class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
         int minX = m;
        int minY = n;
        for (auto v : ops)
        {
            minX = min(minX, v[0]);
            minY = min(minY, v[1]);
        }
        return minX*minY;
    }
};