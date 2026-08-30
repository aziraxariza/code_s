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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q; // bfs ke through
        q.push(root);

        while(!q.empty()){
            int size = q.size();// level ka size lene ke liye
        
            vector<int> level; // iss level walo ke liye

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node == NULL) {
                    level.push_back(INT_MIN); // agar null hai toh INT_MIN dalo compare karne ke liye
                    continue;
                }

                level.push_back(node -> val); // node ki value dalo level mein
            
                q.push(node -> left); // left ki baari
                q.push(node -> right);//  right ki baari
            }

            int l = 0; // l and r like palindrome comparison level mein
            int r = size-1;
            while(l <= r){
                if(level[l] != level[r]) return false; // agar opp end par same nahi 
                l++; // l aage
                r--; // r peeche
            }
        }
        return true;
    }
};