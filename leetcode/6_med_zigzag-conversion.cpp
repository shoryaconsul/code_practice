class Solution {
public:
    string convert(string s, int numRows) {
        string arr[numRows];
        for(int i; i < numRows; i++) arr[i] = "";

        if(numRows == 1) return s;

        int n = 2*numRows - 2;
        for(int i=0; i < s.length(); i++){
            if(i % n < numRows){
                arr[i % n] = arr[i % n] + s[i];
            }
            else{
                arr[2*(numRows-1) - i % n] = arr[2*(numRows-1) - i % n] + s[i];
            }
            
        }

        string res = "";
        for(int i=0; i < numRows; i++){
            // cout << arr[i] << endl;
            res = res + arr[i];
        }

    return res;
    }
};