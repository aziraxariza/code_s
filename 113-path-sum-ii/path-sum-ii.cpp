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
        if(!node) return;

        path.push_back(node->val); // add current node

        if(!node->left && !node->right && target == node->val){
            result.push_back(path); // check if leaf aur req. target achieved
        } 
        else{
            dfs(node->left, target - node->val, path, result); // left
            dfs(node->right, target - node->val, path, result); // right
        }

        path.pop_back();// backtrack iss node ko hatao path se
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path; // for each path

        dfs(root, targetSum, path, result);
        return result;
    }
};