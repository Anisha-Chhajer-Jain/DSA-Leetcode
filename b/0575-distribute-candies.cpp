class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> m;
        for (int c : candyType) m[c]++;
        return min(m.size(), candyType.size() / 2);
    }
};