class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        
        string pre, res = "";
        if(num < 0){
            pre = "-";
            num = -1*num;
        }
        
        while(num >= 1){
            res = to_string(num%7) + res;
            num = num/7;
        } 
        return pre+res;
        
    }
};