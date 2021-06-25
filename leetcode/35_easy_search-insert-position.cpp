class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;  // start search at index 
        int end = nums.size();  // end search at this index - 1
        int mid;
        
        while(end-start > 1){
            mid = start + (end-start)/2;
            //cout<<start<<" "<<mid<<" "<<end<<endl;
            if(target == nums[mid-1]){
                return mid-1;
            }
            else if(target < nums[mid-1]){
                end = mid;
            }
            else{
                start = mid;
            }
        }
        if(target < nums[0]){
            return 0;
        }
        else if(target > nums[nums.size()-1]){
            return nums.size();
        }
        else{
            return start;
        }
    }
};