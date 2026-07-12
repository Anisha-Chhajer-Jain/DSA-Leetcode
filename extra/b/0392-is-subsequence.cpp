class Solution {
public:
    bool isSubsequence(string t, string s) {
        int n=s.size(),m=t.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j<m && s[i]==t[j]){
                j++;
            }
        }
        return j>=m;
    }
};