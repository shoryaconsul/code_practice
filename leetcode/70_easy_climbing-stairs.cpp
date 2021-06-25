class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways(n);
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else{
            ways[0] = 1;  // 1 ways for n=1
            ways[1] = 2;  // 2 ways for n=2
            for(int i=2; i<n; i++){
                ways[i] = ways[i-1] + ways[i-2];
            }
            return ways[n-1];
        }
    }
};