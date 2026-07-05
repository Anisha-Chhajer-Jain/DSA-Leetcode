class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;
        string vowels = "aeiou";
        for (int i = 0; i < 26; i++) {
            char current_char = 'a' + i;
            if (vowels.find(current_char) != string::npos) {
                maxVowelFreq = max(maxVowelFreq, freq[i]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, freq[i]);
            }
        }
        return maxVowelFreq + maxConsonantFreq;
    }
};