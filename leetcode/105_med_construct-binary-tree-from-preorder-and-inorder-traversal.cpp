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
    TreeNode* buildTreeRec(vector<int>& preorder, map<int, int>& inorder_map,
                                int& pre_idx, int in_first, int in_last){
        if(in_first > in_last){  // null case
            return nullptr;
        }
        
        int root_val = preorder[pre_idx];  // root is head of preoder
        int in_idx = inorder_map[root_val];  //position of root_val in inorder
        cout<<pre_idx<<" "<< in_idx<<endl;
        pre_idx++;
        
        TreeNode* root = new TreeNode(root_val);
        root->left = buildTreeRec(preorder, inorder_map, pre_idx, in_first, in_idx-1);
        root->right = buildTreeRec(preorder, inorder_map, pre_idx, in_idx+1, in_last);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 1){  // single node
            TreeNode* root = new TreeNode;
            root->val = preorder[0];
            return root;
        }
        
        map<int, int> inorder_map;  // map with key = node value, value = pos in inorder
        for(int i=0; i<inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        
        int pre_idx = 0;
        return buildTreeRec(preorder, inorder_map, pre_idx, 0, inorder.size()-1);
    }
};