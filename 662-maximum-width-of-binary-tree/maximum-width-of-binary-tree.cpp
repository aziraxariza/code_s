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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q; // CHANGE 1: node ke saath index
        q.push({root, 0});

        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            unsigned long long first, last;
            unsigned long long start = q.front().second; // CHANGE 2: current level ka starting index

            for(int i = 0; i < size; i++){
                auto [node, index] = q.front(); // CHANGE 3: root nahi, current node
                q.pop();

                index = index - start; // CHANGE 4: index normalize

                if(i == 0) first = index; // CHANGE 5: first node ka index
                if(i == size-1) last = index; // CHANGE 6: last node ka index

                if(node->left)
                    q.push({node->left, 2 * index + 1});// CHANGE 7: left index

                if(node->right)
                    q.push({node->right, 2 * index + 2}); // CHANGE 8: right index
            }
            ans = max(ans, (int)(last - first + 1)); // CHANGE 9: actual width
        }
        return ans;
    }
};