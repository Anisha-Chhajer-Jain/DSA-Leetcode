class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> win;
        for(int i=0;i<nums.size();i++){
            win.insert(nums[i]);
            if(i>=k){
                win.erase(win.find(nums[i-k]));
            }
            if(i>=k-1){
                res.push_back(*win.rbegin());
            }
        }
        return res;
    }
};