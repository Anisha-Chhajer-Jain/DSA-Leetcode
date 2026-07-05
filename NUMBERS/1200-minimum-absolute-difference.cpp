class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        multiset<int> ms(arr.begin(),arr.end());
        vector<vector<int>>res;
        int min_diff=INT_MAX;
        for(auto it = ms.begin();next(it)!=ms.end();++it){
            min_diff=min(min_diff,*next(it)-*it);
        }
        for(auto it=ms.begin();next(it)!=ms.end();++it){
            if(*next(it)-*it==min_diff){
                res.push_back({*it,*next(it)});
            }
        }
        return res;
    }
};