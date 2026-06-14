#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<string> ans;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            int minCount = INT_MAX;

            for(string word : words) {
                int count = 0;

                for(char c : word) {
                    if(c == ch)
                        count++;
                }

                minCount = min(minCount, count);
            }

            while(minCount--) {
                ans.push_back(string(1, ch));
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> words = {"bella", "label", "roller"};

    vector<string> result = obj.commonChars(words);

    cout << "Output: ";
    for(string s : result) {
        cout << s << " ";
    }

    return 0;
}