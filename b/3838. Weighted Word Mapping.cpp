class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;

        for (int i = 0; i < words.size(); i++) {
            int sum = 0;

            for (int j = 0; j < words[i].size(); j++) {
                sum += weights[words[i][j] - 'a'];
            }

            int value = sum % 26;
            res.push_back('z' - value);
        }

        return res;
    }
};