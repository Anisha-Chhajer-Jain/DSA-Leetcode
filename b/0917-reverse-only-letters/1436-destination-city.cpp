class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for (auto& p : paths) m[p[0]] = p[1];
        string curr = paths[0][0];
        while (m.count(curr)) curr = m[curr];
        return curr;
    }
};