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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* node;
        TreeNode* curr;
        
        if(!root) return root;
        if(root->left==NULL && root->right==NULL) return root;
        if(root->left==NULL){  // only right child exists
            node = increasingBST(root->right);
            root->right = node;
            return root;
        }
        
        //rebase tree when left child exists
        node = increasingBST(root->left);
        curr = node;
        while(node->right!=NULL){
            node = node->right;
        }
        node->right = root;
        root->left = NULL; 
        root->right = increasingBST(root->right);
        return curr;
        
    }
};