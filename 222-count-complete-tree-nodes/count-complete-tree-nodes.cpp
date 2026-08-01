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
    int leftHeight(TreeNode* root){ // max left height of root
        int h = 0;// initial h is 0
        while(root){  // jab tak root mein kuch hai 
            h++; // +1 for each root
            root = root -> left; // root ab root ka left
        }
        return h; // kya height  aayi left ki
    }

    int rightHeight(TreeNode* root){ // max right height of root
        int h = 0;
        while(root){
            h++;
            root = root -> right;
        }
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh = leftHeight(root); // root ki left height
        int rh = rightHeight(root); // root ki right heighr

        if(lh == rh){ // perfect bt hai
        return (1 << lh) - 1;; // height of perfect bt

        }
        return 1 + countNodes(root -> left) + countNodes(root -> right); // warna hum parent ko kya bhejenge
    }
};