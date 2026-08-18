class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        // Convert s into words
        for (char c : s) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);

        // Number of letters and words must be same
        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {

            char letter = pattern[i];
            string w = words[i];

            if (mp1.count(letter) && mp1[letter] != w)
                return false;

            if (mp2.count(w) && mp2[w] != letter)
                return false;

            mp1[letter] = w;
            mp2[w] = letter;
        }

        return true;
    }
};