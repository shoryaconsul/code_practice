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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> node_q;
        TreeNode* curr;
        node_q.push(root);
        int node_cnt = 1, lvl_cnt = 0;
        while(!node_q.empty()){
            curr = node_q.front();
            node_q.pop();
            node_cnt--;
            
            if(curr->left){
                node_q.push(curr->left);
                lvl_cnt++;
            }
            if(curr->right){
                node_q.push(curr->right);
                lvl_cnt++;
            }
            
            if(node_cnt == 0){
                res.push_back(curr->val);
                node_cnt = lvl_cnt;
                lvl_cnt = 0;
            }
        }
        return res;
    }
};