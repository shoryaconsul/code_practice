class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int curr = INT_MIN;
        int count = 0;
        int pos = 0;
        int i = 0;
        
        while(i < nums.size()){
            curr = nums[i];
            nums[pos] = curr;
            i++;
            count = 1;
            pos++;
                
            while(i<nums.size() && nums[i] == curr){
                if(count == 1){ // add second element
                    nums[pos] = curr;
                    pos++;
                }
                i++;  // advance to end of subsequence
                count++;
            }                   
        }
        return pos;
    }
};