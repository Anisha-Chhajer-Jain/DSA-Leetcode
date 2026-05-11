// #include <iostream>
// using namespace std;

// class Solution {
// public:
//     int climbStairs(int n) {

//         // Base cases
//         if (n <= 2) {
//             return n;
//         }

//         int first = 1;
//         int second = 2;

//         // Find ways step by step
//         for (int i = 3; i <= n; i++) {

//             int third = first + second;

//             first = second;
//             second = third;
//         }

//         return second;
//     }
// };

// int main() {

//     Solution s;

//     int n = 5;

//     cout << s.climbStairs(n);

//     return 0;
// }