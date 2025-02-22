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
    bool isSame(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1  && root2==NULL) return false;
        if(root2 && root1==NULL) return false;
        
        if(root1->val != root2-> val) return false;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool tmp;

        if(subRoot == NULL && root == NULL) return true;
        else if((root == NULL) != (subRoot == NULL)) return false;
        
        tmp = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        if(root->val != subRoot->val){
            return tmp;
        }
        else{
            return isSame(root, subRoot) || tmp;
        }
    }
};