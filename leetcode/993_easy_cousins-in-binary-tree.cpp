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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;
        
        queue<pair<int,TreeNode*>> nodeq;
        int found = 0, valtofind, curr_parent;
        nodeq.push(make_pair(0, root));
        
        while(found == 0){
            queue<pair<int,TreeNode*>> tmp;
            while(nodeq.empty() == false){
                auto [parent, node] = nodeq.front();
                nodeq.pop();
                if(node->val == x){
                    found = 1;
                    valtofind = y;
                    curr_parent = parent;
                    break;
                }
                else if(node->val == y){
                    found = 2;
                    valtofind = x;
                    curr_parent = parent;
                    break;
                }
                else{
                    if(node->left) tmp.push(make_pair(node->val, node->left));
                    if(node->right) tmp.push(make_pair(node->val, node->right));    
                }
            }
            if(found == 0){
                nodeq.swap(tmp);
                if(nodeq.empty()) found=-1;
            }
        }
        
        if(found > 0){
            while(nodeq.empty() == false){
                auto [parent, node] = nodeq.front();
                nodeq.pop();
                if(node->val == valtofind){
                    if(parent == curr_parent) return false;
                    else return true;
                }
            }
            return false;
        }
        else return false;
        
    }
};