/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q){
            return root; 
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q); // left se dekho
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root; // iske left aur right dono se mile

        return left ? left : right; // agar sirf ek koi mila toh woh jisse mila woh return 
    }
};