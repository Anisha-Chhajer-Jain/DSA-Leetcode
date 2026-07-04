class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
            } 
        int ans=1;
        int i=0;
        int j=1;
        map<char,int>mp;
        mp [s[0]] = 1;
        while(j<s.size()){
          while(mp.find(s[j])!=mp.end()){
            mp.erase(s[i]);
            i+=1;
          }
          mp[s[j]]=1;
          j++;
          ans=max(ans,j-i);
        }
        return ans;
    }
};