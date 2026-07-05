class Solution {
public:
    int findLucky(vector<int>& arr) {
        multiset<int> ms(arr.begin(),arr.end());
        int l=-1;
        for(int n: arr){
            if(ms.count(n)==n){
                l=max(l,n);
            }
        }
        return l;
    }
};