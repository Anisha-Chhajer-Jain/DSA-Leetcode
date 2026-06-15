// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         bool check = true;
//         while (check){
//             check=false;
//             if(s.size()<k){
//                 break;
//             }
//             for (int i=0; i<=s.size()-k; i++){
//                 bool n=true;
//                 for (int j=i; j<i+k-1; j++){
//                     if (s[j] != s[j+1]){
//                         n=false;
//                         break;
//                     }
//                 }
//                 if(n){
//                     s.erase(i,k);
//                     check=true;
//                     break;
//                 }
//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans="";
        vector<int> count;

        for (char ch:s){
            ans.push_back(ch);
            if(ans.size()==1 || ans.back()!=ans[ans.size()-2]){
                count.push_back(1);
            } 
            else{
                count.push_back(count.back() + 1);
            }
            if(count.back() == k){
                for (int i = 0; i < k; i++){
                    ans.pop_back();
                    count.pop_back();
                }
            }
        }
        return ans;
    }
};