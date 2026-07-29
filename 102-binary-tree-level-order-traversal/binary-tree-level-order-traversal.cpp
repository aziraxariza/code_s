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
        vector<vector<int>> ans;

        if(!root) return ans; // kuch hai hi nahi; 

        queue<TreeNode*> q; // ek q to store node -> val
        q.push(root);

        while(!q.empty()){
            int size = q.size(); // no. of eles in q at same level
            vector<int> level; // to store eles at same level

            for(int i = 0; i < size; i++){ // jitne same level par hai traverse them
                TreeNode* node = q.front(); // q ki first value ban gayi node
                q.pop();
                level.push_back(node -> val); // current level par add kar diya same level walo ko

                if(node -> left) q.push(node -> left); // ab left mein hai toh usko daal do q mein for next level 
                if(node -> right) q.push(node -> right); // ab right mein hai toh usko daal do q mein for next level 
            }
            ans.push_back(level); // current level ko daal diya ans mein
        }
        return ans;
    }
};