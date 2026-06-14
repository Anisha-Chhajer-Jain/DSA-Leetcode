#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        string ans;

        for (char ch : s) {
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            } else {
                ans += ch;
            }
        }

        return ans;
    }
};
