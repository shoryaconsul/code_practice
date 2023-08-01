class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;

        vector<int> nums = {1};
        int i2 = 0, i3 = 0, i5 = 0;
        int n2 = 2, n3 = 3, n5 = 5;
        int curr;
        while(nums.size() < n){
            // cout << n2 << " " << n3 << " " << n5 << endl;
            curr = min({n2, n3, n5});
            nums.push_back(curr);
            
            if(curr == n2){
                i2++;
                n2 = 2*nums[i2];
            }
            if(curr == n3){
                i3++;
                n3 = 3*nums[i3];
            }
            if(curr == n5){
                i5++;
                n5 = 5*nums[i5];
            }
            // cout << nums[nums.size() - 1] << endl;
        }

        return nums[n-1];
    }
};