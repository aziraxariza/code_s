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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // final ans
        if(!root) return ans;

        queue<TreeNode*> q; // nodes store karega level wise
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level; // ek lvl ke nodes

            while(size--){
                TreeNode* node = q.front(); // take nodes
                q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); // push unke bacche
            }
            ans.push_back(level);
        }
        return ans;
    }
};