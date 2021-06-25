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
    TreeNode* arrToBST(vector<int>& nums, int start, int end) {
        int mid;

        if(start > end){
            return nullptr;
            }
        else{
            TreeNode* res = new TreeNode();
            mid = start + (end-start)/2;
            res->val = nums[mid];
            res->left = arrToBST(nums, start, mid-1);
            res->right = arrToBST(nums, mid+1, end);
            return res;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrToBST(nums, 0, nums.size()-1);
    }
};