class Solution {
public:
    int countAsterisks(string s) {
        int count=0;int c=0;
        bool check=false;
        for (int i=0;i<s.size();i++){
            if(s[i]=='*'&& check==false ){
                count++;
            }
            else if(s[i]=='|'){
                 check=true;
                 c++;
                 if(c==2){
                    check=false;
                    c=0;
                 }
            }
        }
        return count;
    }
};