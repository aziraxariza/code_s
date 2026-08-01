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
    unordered_map<int, int> mp;   // value -> inorder index
    int idx = 0;                  // current preorder index

    TreeNode* build(vector<int>& preorder, int left, int right){

        if(left > right) return NULL;      // no nodes left
        int val = preorder[idx++];         // current root from preorder

        TreeNode* root = new TreeNode(val);
        int mid = mp[val];                 // root position in inorder

        root->left = build(preorder, left, mid - 1);     // build left subtree
        root->right = build(preorder, mid + 1, right);   // build right subtree

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};