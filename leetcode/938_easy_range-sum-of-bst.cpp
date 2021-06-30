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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        TreeNode* node;
        queue<TreeNode*> node_q;
        node_q.push(root);
        while(!node_q.empty()){
            node = node_q.front();
            node_q.pop();
            
            if(node->val>=low && node->val<=high){
                sum = sum + node->val;
                if(node->left) node_q.push(node->left);
                if(node->right) node_q.push(node->right);
            }
            else if(node->val<low){
                if(node->right) node_q.push(node->right);
            }
            else{ //node->val>high
                if(node->left) node_q.push(node->left); 
            }
        }
        return sum;
    }
};