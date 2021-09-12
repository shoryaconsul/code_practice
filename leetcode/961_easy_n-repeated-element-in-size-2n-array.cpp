class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> el;
        int i;
        for(i=0; i<nums.size(); i++){
            if(el.find(nums[i]) == el.end()){ //element not found
                el.insert(nums[i]);
            }
            else break;
        }
        return nums[i];
    }
};