#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        int count = 0;

        int sum = divisor;

        // Keep adding divisor until it becomes greater
        while (sum <= dividend) {

            sum = sum + divisor;

            count++;
        }

        return count;
    }
};

int main() {

    Solution s;

    int dividend = 10;
    int divisor = 2;

    cout << s.divide(dividend, divisor);

    return 0;
}