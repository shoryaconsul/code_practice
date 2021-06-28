class Solution {
public:
    bool isUgly(int n) {
        if(n==1) return true;
        while(n>0){
            if(n%2 > 0) break;
            else n=n/2;
        }
        while(n>0){
            if(n%3 > 0) break;
            else n=n/3;
        }
        while(n>0){
            if(n%5 > 0) break;
            else n=n/5;
        }
        if(n==1) return true;
        else return false; 
    }
};