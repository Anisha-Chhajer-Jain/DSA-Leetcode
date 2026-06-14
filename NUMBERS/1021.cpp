// Last updated: 6/9/2026, 3:50:29 PM
1class Solution {
2public:
3    vector<string> commonChars(vector<string>& words) {
4        vector<string> ans;
5
6        for (char ch = 'a'; ch <= 'z'; ch++) {
7            int minCount = INT_MAX;
8
9            for (string word : words) {
10                int count = 0;
11
12                for (char c : word) {
13                    if (c == ch) count++;
14                }
15
16                minCount = min(minCount, count);
17            }
18
19            while (minCount--) {
20                ans.push_back(string(1, ch));
21            }
22        }
23
24        return ans;
25    }
26};