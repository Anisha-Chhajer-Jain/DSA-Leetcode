class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        char curr = 'a';
        for (char c : key) {
            if (c != ' ' && !m.count(c)) m[c] = curr++;
        }
        string res = "";
        for (char c : message) {
            if (c == ' ') res += ' ';
            else res += m[c];
        }
        return res;
    }
};