class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 10000, j, k, tmp;
        for(int i=0; i<nums.size(); i++){
            j = i+1;
            k = nums.size()-1;
            while(j<k){
                tmp = nums[i]+nums[j]+nums[k];
                // cout<<"Indices: "<<i<<" "<<j<<" "<<k<<endl;
                // cout<<sum<<" "<<tmp<<" "<<target<<endl;
                if(abs(sum-target) > abs(tmp-target)){
                    sum = tmp;
                }
                if(tmp == target){
                    cout<<"Returning"<<endl;
                    return tmp;
                }
                else if(tmp < target) j++;
                else k--;
            }
        }
        return sum;
    }
};