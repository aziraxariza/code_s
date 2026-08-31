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
    void dfs(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;

        // add current node
        path.push_back(node->val);

        // check leaf
        if (!node->left && !node->right && target == node->val) {
            result.push_back(path);
        } else {
            dfs(node->left, target - node->val, path, result);
            dfs(node->right, target - node->val, path, result);
        }

        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;

        dfs(root, targetSum, path, result);
        return result;
    }
};