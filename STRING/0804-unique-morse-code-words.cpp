class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>code={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string>transform;
        for(const string& word:words){
            string morse="";
            for(char c: word){
                morse+=code[c-'a'];
            }
            transform.insert(morse);
        }
        return transform.size();
    }
};