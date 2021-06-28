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
    int sum_tilt = 0;
public:
    int findSum(TreeNode* root){  //find sum of node values
        if(!root) return 0;
        
        int leftSum = findSum(root->left);
        int rightSum = findSum(root->right);
        
        sum_tilt = sum_tilt + abs(leftSum - rightSum);
        // cout<<root->val<< " "<< sum_tilt<<endl;
        
        return leftSum + rightSum + root->val;
        
    }
    
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        
        int tmp = findSum(root);
        return sum_tilt;
    }
};