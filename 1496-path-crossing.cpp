class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> dir = {{'N',{0,1}}, {'S',{0,-1}}, {'E',{1,0}}, {'W',{-1,0}}};
        unordered_map<string, bool> visited;
        int x = 0, y = 0;
        visited["0,0"] = true;
        for (char c : path) {
            x += dir[c].first; y += dir[c].second;
            string hash = to_string(x) + "," + to_string(y);
            if (visited[hash]) return true;
            visited[hash] = true;
        }
        return false;
    }
};