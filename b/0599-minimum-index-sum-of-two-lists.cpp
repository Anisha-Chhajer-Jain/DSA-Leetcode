class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> m;
        int min_val = INT_MAX; 
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            if (m.count(list2[i]) != 0) {
                int current_sum = m[list2[i]] + i;
                if (current_sum < min_val) {
                    min_val = current_sum;
                    res.clear(); 
                    res.push_back(list2[i]);
                } 
                else if (current_sum == min_val) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};