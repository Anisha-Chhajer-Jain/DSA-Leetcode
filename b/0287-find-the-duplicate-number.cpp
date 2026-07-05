class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         unordered_set<int> s;
//         for (int i = 0; i < nums.size(); i++) {
//             if (s.count(nums[i])) {
//                 return nums[i];
//             } else {
//                 s.insert(nums[i]); 
//             }
//         }
//         return -1; 
//     }
// };



   
     unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] > 1) {
                return nums[i];
            }
        }
        return -1;
    }
};