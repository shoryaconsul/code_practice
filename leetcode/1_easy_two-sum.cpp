class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2);  //Result
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
                
            }
        }
    return res;
    }
};