class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < ransomNote.length(); i++) {
            bool found = false;

            for (int j = 0; j < magazine.length(); j++) {
                if (ransomNote[i] == magazine[j]) {
                    found = true;
                    magazine[j] = '*'; // mark as used
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};