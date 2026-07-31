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
    vector<int> rightSideView(TreeNode* root) { //bfs karenge since level wise last ele
        vector<int> ans;
        if(!root) return ans;// koi nahi tha node

        queue<TreeNode*> q; // q to store nodes
        q.push(root); // root ko sabse pehle dala

        while(!q.empty()) {
            int n = q.size(); //current level size

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop(); // pop karte jao jab tak last ele na aaye level ka

                if(i == n - 1) //mila aakhri node of this level
                    ans.push_back(node->val); //ans mein dalo

                if(node->left) q.push(node->left); // repeat for left child
                if(node->right) q.push(node->right); // repeat for right child
            }
        }

        return ans; // ans bheja of all righties
    }
};