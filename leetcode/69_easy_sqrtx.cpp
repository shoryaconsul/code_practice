class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        
        int res = 1;
        while(x/res >= res){
            res = res + 1;
        }
        return res - 1;
    }
};