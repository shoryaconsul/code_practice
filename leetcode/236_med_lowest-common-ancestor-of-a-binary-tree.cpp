/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, TreeNode*> pos_node;
        queue<pair<int, TreeNode*>> node_q;
        pair<int, TreeNode*> curr;
        int pos_p, pos_q;
        
        node_q.push(make_pair(0,root));
        while(!node_q.empty()){  //BFS traversal
            curr = node_q.front();
            node_q.pop();
            pos_node[curr.first] = curr.second;
            if(curr.second == p) pos_p = curr.first;
            if(curr.second == q) pos_q = curr.first;
            
            if(curr.second->left) node_q.push(make_pair(2*curr.first+1, curr.second->left));
            if(curr.second->right) node_q.push(make_pair(2*curr.first+2, curr.second->right));
            
        }
        cout<<pos_p<<" "<<pos_q<<endl;
        while(pos_p != pos_q){
            if(pos_p < pos_q){
                pos_q = (pos_q-1)/2;
            }
            else{
                pos_p = (pos_p-1)/2;
            }
        }
        return pos_node[pos_p];
    }
};