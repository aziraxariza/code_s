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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans; // final ans
        if(!root) return ans;

        queue<TreeNode*> q; // q for nodes
        q.push(root); // sabse pehle root daala

        while(!q.empty()){
            int sz = q.size(); // ek lvl par kitne nodes
            int maxi = INT_MIN; // max for each level ko track krne ke liye

            while(sz--){
                TreeNode* node = q.front(); // node liya
                q.pop();
                maxi = max(maxi, node->val); // update maxi w lvl ka sabse bada 

                if(node->left) q.push(node->left); // agar left child hai toh
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxi); // iss lvl ka maxi push kiya
        }
        return ans;
    }
};