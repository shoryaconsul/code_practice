class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        for(int i=n/5; i >= 1; i=i/5){
            num = num + i;
        }
        return num;
    }
};