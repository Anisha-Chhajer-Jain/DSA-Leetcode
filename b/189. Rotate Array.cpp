#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        nums = temp;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    obj.rotate(nums, k);

    cout << "Rotated Array: ";
    for (int num : nums) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}