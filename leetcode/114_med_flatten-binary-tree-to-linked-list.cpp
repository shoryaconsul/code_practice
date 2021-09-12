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
    TreeNode* flattenRecursive(TreeNode* root){
        if(!root) return nullptr;
        if(root->left == NULL && root->right == NULL) return root;
        
        if(root->left == NULL){  // only right child
            return flattenRecursive(root->right);
        }
        
        // both children exist
        TreeNode* tmp = root->right;
        TreeNode* tail;
        tail = flattenRecursive(root->left);
        root->right = root->left;
        root->left = NULL;
        tail->right = tmp;
        if(tmp != NULL) tail = flattenRecursive(tail->right);
        
        return tail;
    }
    
    void flatten(TreeNode* root) {
        TreeNode* dummy;
        dummy = flattenRecursive(root);
    }
};