class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tmp, i, j;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        
        if(i>=0){
            j = nums.size()-1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        
        for(int start=i+1, end=nums.size()-1; start<end; start++, end--){
            swap(nums[start], nums[end]);
        }
        
    }
};