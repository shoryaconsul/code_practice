class Solution {
public:
    int findPeak(vector<int>& nums, int start, int end, int& peak){
        if(end-start == 1){
            peak = nums[start];
            return start;
        }
        int mid = (start+end)/2;
        int left_peak = findPeak(nums, start, mid, peak);
        int right_peak = findPeak(nums, mid, end, peak);
        if(nums[left_peak] >= nums[right_peak]){
            peak = nums[left_peak];
            return left_peak;
        }
        else{
            peak = nums[right_peak];
            return right_peak;
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int peak = INT_MAX;
        return findPeak(nums, 0, nums.size(), peak);
    }
};