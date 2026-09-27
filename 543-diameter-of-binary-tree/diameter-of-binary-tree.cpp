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

    int heightD(TreeNode* root, int& diameter){
        if(!root) return 0;

        int lh = heightD(root->left, diameter);
        int rh = heightD(root->right, diameter);

        diameter = max(diameter, lh+rh); // diameter = sum of rh aur lh

        return 1 + max(lh, rh); // height of node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heightD(root, diameter);
        return diameter; 
    }
};