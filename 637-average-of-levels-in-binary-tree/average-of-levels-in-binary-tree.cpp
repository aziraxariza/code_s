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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans; // final ans
        if(!root) return ans;

        queue<TreeNode*> q; // q for nodes
        q.push(root); // first root node

        while(!q.empty()){
            double sz = q.size(); // ek level par total kitne
            double szSum = 0;

            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                szSum += node->val; // isme val add

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); // agar left right child hai 
            }
            ans.push_back(szSum/sz); // avg calc karke dalo
        }
        return ans;
    }
};