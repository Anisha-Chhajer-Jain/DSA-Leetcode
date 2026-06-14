#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        // If either number is 0
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n + m, 0);

        // Multiply digits from right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + ans[i + j + 1];

                ans[i + j + 1] = sum % 10; // Current digit
                ans[i + j] += sum / 10;    // Carry
            }
        }

        string result = "";

        // Convert vector to string
        for (int digit : ans) {
            if (!(result.empty() && digit == 0)) {
                result += to_string(digit);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    string num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Product = " << obj.multiply(num1, num2) << endl;

    return 0;
}