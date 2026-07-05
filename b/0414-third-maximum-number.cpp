class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());//s={1,2,3}
        if(s.size()<3){//false
            return *s.rbegin();
        }
        auto it=s.rbegin();//it={3}
        *it++;
        *it++;
        return *it;
    }
};