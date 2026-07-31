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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes; // {col, row, value} ki tarah store for each node
        queue<tuple<TreeNode*, int, int>> q; // {node, row, col} type node prepare

        q.push({root, 0, 0});// pehle ko daala q mein

        while(!q.empty()) {
            auto [node, row, col] = q.front(); // auto take kis type ka val in q
            q.pop();
            nodes.push_back({col, row, node->val}); // isko store karo nodes mein {col, row, val}

            if(node->left) // iska left hai toh
                q.push({node->left, row + 1, col - 1}); //usko dalo in q w its {node, its row, its col}
            if(node->right) // same for right child
                q.push({node->right, row + 1, col + 1});
        }

        sort(nodes.begin(), nodes.end()); // col -> row -> value, wise check for sort

        vector<vector<int>> ans; // final ans ke liye
        int prevCol = INT_MIN;

        for(auto [col, row, val] : nodes) {
            if(col != prevCol) {
                ans.push_back({}); // new vertical column
                prevCol = col;
            }
            ans.back().push_back(val); // only value goes into answer
        }

        return ans;
    }
};