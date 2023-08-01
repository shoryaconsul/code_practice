class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0 | n == 1) return n;

        vector<int> nums = {0, 1};
        int max_val = 1;  // max value
        int q, r, val;

        for(int i=2; i<=n; i++){
            r = i % 2; // remainder
            q = i >> 1; // quotient
            if(r == 0){
                nums.push_back(nums[q]);
            }
            else{
                val = nums[q] + nums[q+1];
                nums.push_back(val);
                if(val > max_val){max_val = val;}
            }
        }
        return max_val;
    }
};