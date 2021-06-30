class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        int mid;
        
        while(start+2 <= end){
            mid = start + (end-start)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            
            if(arr[mid] > arr[mid-1]){  // peak lies to the right of mid
                start = mid + 1;
            }
            else{  // peak lies to the left of mid
                end = mid - 1;
            }
        }
        if(start == end) return start;
        if(arr[start] > arr[end]) return start;
        return end;
    }
};