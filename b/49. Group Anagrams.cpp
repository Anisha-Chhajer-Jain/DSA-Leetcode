// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& str) {

//         map<string, vector<string>> mp;

//         for (int i = 0; i < str.size(); i++) {
//             string s = str[i];
//             sort(s.begin(), s.end());

//             mp[s].push_back(str[i]);
//         }

//         vector<vector<string>> ans;

//         for (auto &x : mp) {
//             ans.push_back(x.second);
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());

            mp[temp].push_back(s);
        }

        vector<vector<string>> result;

        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
