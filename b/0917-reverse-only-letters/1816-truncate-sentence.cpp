class Solution {
public:
    string truncateSentence(string s, int k) {
        int  sp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
               sp+=1;
            }
            if(sp==k){
               return s.substr(0,i);
            }
        }
        return s;
    }
};