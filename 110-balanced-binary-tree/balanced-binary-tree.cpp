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
    int height(TreeNode* root) {
        if(!root) return 0;

        int left = height(root->left); // left subtree ki height
        int right = height(root->right); // right subtree height

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left = height(root->left); // left height
        int right = height(root->right);// right height

        if(abs(left - right) > 1) return false; // current node unbalanced

        return isBalanced(root->left) && isBalanced(root->right); // har ek node ke liye
    }
};