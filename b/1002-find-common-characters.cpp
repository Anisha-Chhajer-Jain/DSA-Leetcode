class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        char ch;
        bool check;
        string s;
        vector<string> ans;
        for(int i = 0; i < words[0].size(); i++){
            ch = words[0][i];
            s = "";
            for(int j = 1; j < words.size(); j++){
                check = false;
                for(int k = 0; k < words[j].size(); k++){
                    if(ch == words[j][k]){
                        words[j][k] = '1';
                        check = true;
                        break;
                    }
                }
                if(check == false) break;
            }
            s += ch;
            if(check == true) ans.push_back(s);
        }
        return ans;
    }
};