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
        if(!root) return 0;

        int left = max(0, solve(root->left, maxi)); // negative paths ignore karenge --> agar iss path se add karke value kum ho rahi toh mat lo 
        int right = max(0, solve(root->right, maxi));     

        maxi = max(maxi, root->val + left + right); // best path through current node aur uski family

        return root->val + max(left, right); // iss node ki family ki kya value hai total wapas bhejo
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;// sabse chhotu keep maxi ko

        solve(root, maxi); // fn call for maxi calc

        return maxi; // ye lo max sum
    }
};