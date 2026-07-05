class Solution {
public:
    int minPairSum(vector<int>& nums) {
        multiset<int>ms(nums.begin(),nums.end());
        int max_sum=0;
        while(!ms.empty()){
            auto smallest=ms.begin();
            auto largest=prev(ms.end());
            max_sum=max(max_sum,*smallest+*largest);
            ms.erase(smallest);
            ms.erase(largest);
        }
        return max_sum;
    }
};