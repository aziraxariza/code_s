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
    int height(TreeNode* root, int &diameter) {
        if(root == NULL) return 0;

        int lh = height(root->left, diameter); // left child as node se diameter update ho jayega if max sath hi height from left side pata chal jayegi
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh+rh); // sath sath diameter update for each node
        return 1 + max(lh, rh); // height for each node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // shuruat
        height(root, diameter); // recursive fn to get max diameter from each node
        return diameter; 
    }
};