class Solution {
public:
    int maxProduct(vector<int>& nums) {
        multiset<int> ms(nums.begin(),nums.end());
        auto it=prev(ms.end());
        int val1=*it;
        int val2=*prev(it);
        return (val1-1)*(val2-1);
    }
};