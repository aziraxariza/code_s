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
    TreeNode* findMin(TreeNode* root) {
        while(root->left) // keep moving left
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        // jab tak na mile key wali node.. dhundho dono sides
        if(key < root->val) { // search in left subtree 
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) { // search in right subtree
            root->right = deleteNode(root->right, key);
        }
        else {                                          // node found

            if(root->left == NULL && root->right == NULL) { // no child
                delete root;
                return NULL;
            }

            if(root->left == NULL) {// only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == NULL) { // only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* succ = findMin(root->right); // inorder successor --> min val in right subtree
            root->val = succ->val; // copy value
            root->right = deleteNode(root->right, succ->val); // delete duplicate
        }
        return root;
    }
};