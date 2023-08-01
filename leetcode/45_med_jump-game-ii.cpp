class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> num_jumps(n, n);

        num_jumps[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=1; j<=nums[i] && i+j <n; j++){
                num_jumps[i+j] = min(num_jumps[i+j], num_jumps[i] + 1);
                if(i+j == n-1) return num_jumps[n-1];
            }
            // cout << i << " " << num_jumps[i] << endl;
        }

        return num_jumps[n-1];
    }
};