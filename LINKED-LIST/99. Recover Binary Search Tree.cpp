/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nodes;
    vector<int> values;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);
        nodes.push_back(root);
        values.push_back(root->val);
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        vector<int> sorted = values;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < values.size(); i++) {
            if (values[i] != sorted[i]) {
                nodes[i]->val = sorted[i];
            }
        }
    }
};