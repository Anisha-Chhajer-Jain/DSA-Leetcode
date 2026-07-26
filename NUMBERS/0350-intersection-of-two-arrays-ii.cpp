class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>ms(nums1.begin(),nums1.end());
        vector<int> res;
        for(int n :nums2){
            auto it=ms.find(n);
            if(it!=ms.end()){
                res.push_back(n);
                ms.erase(it);
            }
        }
        return res;
    }
};