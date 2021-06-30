class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int curr, imax, cmax = 0, csecond = 0;
        for(int i=0; i<nums.size(); i++){
            curr = nums[i];
            if(curr > cmax){  // new max element
                csecond = cmax;
                cmax = curr;
                imax = i;
            }
            else if(curr > csecond){  // new second largest element
                csecond = curr;
            }
        }
        
        if(cmax >= 2*csecond) return imax;
        return -1;
        
    }
};