/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        q.push(root); // sabse pehle node se shuru mapping

        while(!q.empty()) { //normal bfs + parent mapping
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parent[node->left] = node; // child -> parent mapping
                q.push(node->left); // push into q
            }
            if(node->right) {
                parent[node->right] = node; // child -> parent map karo
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> visited; // to keep track of vis nodes
        q.push(target);
        visited.insert(target); // mark target ko visited sabse pehle 

        int distance = 0; // dist track karne ke liye

        while(!q.empty() && distance < k) { //jab tak distance k se ek kum tab tak chalo kuki k hogi jab tum req node par pohoch jaoge

            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // sabse aage q mein kaun 
                q.pop();

                if(node->left && !visited.count(node->left)) { // left child ko dalo in q if unvisited
                    q.push(node->left);
                    visited.insert(node->left); //mark visited
                }
                if(node->right && !visited.count(node->right)) { // right child ko dalo if unvisited
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent.count(node) && !visited.count(parent[node])) { // iska parent hai && unvisited hai use dalo in q
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            distance++; // hum ek kadam ab aage badhenge current node se
        }

        vector<int> ans;
        while(!q.empty()) { // jo bach gaye i.e jin tak pahuchne mein distance k ban gayi woh 

            ans.push_back(q.front()->val); // exactly K distance wale nodes ki vals in ans
            q.pop();
        }
        return ans;
    }
};