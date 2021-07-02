class Solution {
public:    
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid;
        while(start <= end){
            mid = (end + start)/2;
            cout<<start<<" "<<end <<" "<<mid<<endl;

            if(nums[mid] == target) return mid;
            
            if(nums[start] < nums[end]){ //pivot does not lie between start and end
                if(nums[mid] < target){ // target lies to the right of mid
                    start = mid+1;
                }
                else{  // target lies to the left of mid
                    end = mid-1;
                }
            }
            else{  // pivot lies between start and end
                if(nums[start] > nums[mid]){ // pivot lies between start and mid
                    if(nums[mid] > target){ // nums[end] > nums[mid]
                        end = mid-1;
                    }
                    else{ //
                        if(nums[end] < target) end = mid-1;
                        else start = mid+1;
                    }
                }
                else{  // pivot lies between mid and end
                    if(nums[mid] < target){ // nums[start] < nums[mid]
                        start = mid+1;
                    }
                    else{
                        if(nums[start] <= target) end = mid-1;
                        else start = mid+1;
                    }
                }
            }
        }
        return -1;
    }
};