// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {

//         int n = matrix.size();

//         // Transpose matrix
//         for (int i = 0; i < n; i++) {

//             for (int j = i + 1; j < n; j++) {

//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

//         // Reverse every row
//         for (int i = 0; i < n; i++) {

//             // reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
// };

// int main() {

//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     Solution s;

//     s.rotate(matrix);

//     // Print rotated matrix
//     for (int i = 0; i < matrix.size(); i++) {

//         for (int j = 0; j < matrix[i].size(); j++) {

//             cout << matrix[i][j] << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }