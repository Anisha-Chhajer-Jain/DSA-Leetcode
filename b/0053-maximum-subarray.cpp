class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr =0;
         int n=nums.size();
        int ans=nums[0];
        for(int i=0;i<n;i++){
            curr+=nums[i];
            if(curr>ans){
                ans=curr;
            }
             if(curr<0){
                curr=0;
            }
        }
        return ans;
    }
};