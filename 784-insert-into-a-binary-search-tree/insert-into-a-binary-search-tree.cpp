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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) // agar khali toh add new node
            return new TreeNode(val);

        if(val < root->val) // val curr node ki val se kum 
            root->left = insertIntoBST(root->left, val); // isko fir curr node ke left mein dalo
        else// val cur node ke val se zyada toh usko cur node ke right mein daalo
            root->right = insertIntoBST(root->right, val); // right side ke liye recursive call

        return root; // return root karna tha
    }
};