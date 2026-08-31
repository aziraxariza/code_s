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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;// final ans 2d
        if(!root) return ans;// kuch hai hi nahi

        queue<TreeNode*> q;// humara q
        q.push(root);// root ko dala

        int cnt = 0;//cnt to keep check of alternate

        while(!q.empty()) {
            int size = q.size();//no. of nodes at same level
            vector<int> level;// isko ans mein dalenge

            for(int i = 0; i < size; i++) { // same level no. of nodes tak loop
                TreeNode* node = q.front(); // aage ko uthaya
                q.pop(); //nikala

                level.push_back(node->val); // ans mein dala node ki val

                if(node->left) q.push(node->left);      // BFS always normal
                if(node->right) q.push(node->right); // current node k dono bacche dalo
            }

            if(cnt % 2 == 1) // ab agar alternate hai toh ulta karo level ko
                reverse(level.begin(), level.end()); // alternate ke liye reverse kardo level mein dali hui cheezein

            ans.push_back(level); // finally level ko answer mein dalo
            cnt++; // ab next alt ke liye cnt change
        }

        return ans;
    }
};