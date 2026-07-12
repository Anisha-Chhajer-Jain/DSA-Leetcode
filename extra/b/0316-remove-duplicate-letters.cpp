class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> arr(26,0);
        vector<bool> vis(26,false);
        string ans ="";
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']--;
            if(vis[s[i]-'a'])continue;
            while(!ans.empty() && ans.back()>s[i] && arr[ans.back()-'a']>0){
               vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            vis[s[i]-'a']=true;
            ans.push_back(s[i]);
        }
        return ans;

    }
};