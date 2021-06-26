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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        stack<TreeNode*> node_stack;  // DFS stack
        stack<int> pathsum;  // Stack of path sums
        TreeNode* curr;
        int sum_curr;
        node_stack.push(root);
        pathsum.push(root->val);

        while(!node_stack.empty()){
            curr = node_stack.top();
            node_stack.pop();
            sum_curr = pathsum.top();
            pathsum.pop();
            
            if (curr->left==NULL && curr->right==NULL){ // leaf node
                if (sum_curr == targetSum) return true;
            }
            if(curr->left){ // left node
                node_stack.push(curr->left);
                pathsum.push(sum_curr + curr->left->val);
            }
            if(curr->right){ // right node
                node_stack.push(curr->right);
                pathsum.push(sum_curr + curr->right->val);
            }
        }
        return false;
    }
};