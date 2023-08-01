class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, end=1;
        int sum = 0, best = INT_MAX;
        while(end <= nums.size()){
            sum = sum + nums[end-1];
            while(sum >= target){
                best = min(best, end-start);
                sum = sum - nums[start];
                start++;
            }
            end++;
        }
        if(best==INT_MAX) return 0;
        else return best;
    }
};