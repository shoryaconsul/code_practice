class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1;  // indices in nums1, nums2
        int curr = m+n-1;  // index for combined array
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[curr] = nums1[i];
                i--;
            }
            else{ // nums1[] <= nums2[j]
                nums1[curr] = nums2[j];
                j--;
            }
            curr--;
        }
        if(i < 0 && j>=0){
            while(j >= 0){
                nums1[curr] = nums2[j];
                j--;
                curr--;
            }
        }
    }
};