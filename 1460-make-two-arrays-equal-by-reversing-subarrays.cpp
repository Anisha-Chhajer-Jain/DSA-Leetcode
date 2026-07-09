class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        multiset<int> ms1(target.begin(),target.end());
        multiset<int> ms2(arr.begin(),arr.end());
        return ms1 == ms2;
    }
};