#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        // If any number is 0
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n + m, 0);

        // Multiply from back
        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 0; j--) {

                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + ans[i + j + 1];

                ans[i + j + 1] = sum % 10;

                ans[i + j] = ans[i + j] + sum / 10;
            }
        }

        string result = "";

        // Convert vector to string
        for (int x : ans) {

            // Skip starting zeros
            if (!(result == "" && x == 0)) {
                result = result + to_string(x);
            }
        }

        return result;
    }
};

int main() {

    Solution s;

    string num1 = "123";
    string num2 = "45";

    cout << s.multiply(num1, num2);

    return 0;
}