class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string res = "";
        int offset = (int)('0'); // decimal value of '0'
        int carry = 0;
        int v1, v2, v;
        
        for(i,j; max(i, j)>=0; i--,j--){
            if(i>=0) v1 = (int)(num1[i]) - offset;
            else v1 = 0;
            
            if(j>=0) v2 = (int)(num2[j]) - offset;
            else v2 = 0;
    
            v = v1 + v2 + carry;
            if(v >=10){
                carry = 1;
                res = (char)(v+offset-10) + res;
            }
            else{  // v < 10
                carry = 0;
                res = (char)(v+offset) + res;
            }
        }
        
        if(carry>0){
            res = (char)(carry + offset) + res;   
        }
        return res;
        
    }
};