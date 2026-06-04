#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Square each element
    for (int i = 0; i < n; i++) {
        nums[i] = nums[i] * nums[i];
    }

    // Sort the array
    sort(nums.begin(), nums.end());

    // Print result
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}