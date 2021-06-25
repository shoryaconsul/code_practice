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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> node_stack;
        vector<int> res;
        TreeNode* node_curr;
        while(root != NULL || node_stack.empty()==false){
            while(root != NULL){
                node_stack.push(root);
                root = root->left;
            }
            node_curr = node_stack.top();
            node_stack.pop();
            res.push_back(node_curr->val);
            root = node_curr->right;
        }
        return res;        
    }
};