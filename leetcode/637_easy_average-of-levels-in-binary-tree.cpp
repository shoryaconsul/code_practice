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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> level_avg;
        queue<TreeNode*> node_lvl;
        queue<TreeNode*> node_next;
        bool done = false;
        double sum;
        double lvl_count;
        
        node_lvl.push(root);
        
        while(!done){
            sum = 0;
            lvl_count = 0;
            node_next = queue<TreeNode*>();
            float avg;
            while(node_lvl.empty() == false){
                TreeNode* node = node_lvl.front();
                node_lvl.pop();
                sum = sum + node->val;
                lvl_count = lvl_count + 1;
                if(node->left) node_next.push(node->left);
                if(node->right) node_next.push(node->right);
            }
            if(lvl_count==0) done = true;
            else{
                level_avg.push_back(sum/lvl_count);
                node_lvl.swap(node_next);
            }
        }
        return level_avg;
    }
};