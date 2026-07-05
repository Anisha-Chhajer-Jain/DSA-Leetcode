class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m;
        for (char c : chars) m[c]++;
        int res = 0;
        for (string w : words) {
            unordered_map<char, int> temp = m;
            bool good = true;
            for (char c : w) {
                if (--temp[c] < 0) { good = false; break; }
            }
            if (good) res += w.size();
        }
        return res;
    }
};