class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> val_pos;
        int max_subseq = 0, cnt = 0;
        int val, j=0;
        
        for(int i=0; i<n; i++) val_pos[nums[i]] = i;
        
        while(j < n){
            val = nums[j];
            cnt = 1;
            if(val_pos.find(val-1) == val_pos.end()){  // val - 1 not in list
                val++;
                while(val_pos.find(val) != val_pos.end()){
                    cnt++;
                    val++;
                }
                max_subseq = max(cnt, max_subseq);
            }
            j++;
        }
        return max_subseq;
    }
};