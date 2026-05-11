class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        int count = 0;

        // Keep subtracting divisor
        while (a >= b) {
            a = a - b;
            count++;
        }

        // Make answer negative if signs are different
        if ((dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0)) {
            count = -count;
        }

        return count;
    }
};