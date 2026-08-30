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

        queue<TreeNode*> q; // nodes store karega
        q.push(root); // initial root push

        while(!q.empty()){
            int size = q.size(); // to take all nodes at one level
            vector<int> level; // for each level nodes

            while(size--){
                TreeNode* node = q.front();
                q.pop(); 

                level.push_back(node->val); // iss level mein dalo

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level); // ye level ans mein dala
        }
        return ans;
    }
};