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
    int solve(TreeNode* root, int &maxi) {
        if(!root) return 0; // no node 0 return

        int left = max(0, solve(root->left, maxi)); // negative children nahi lenge
        int right = max(0, solve(root->right, maxi));

        maxi = max(maxi, root->val + left + right); // har fam se bottom up maxi dekho

        return root->val + max(left, right); //har fam ki value return
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;// initially

        solve(root, maxi); // fn call for maxi calc

        return maxi; // ye lo max sum
    }
};