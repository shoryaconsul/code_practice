class Solution {
public:
    string reverseOnlyLetters(string s) {
        for(int i=0, j = s.size()-1; i<j; i++,j--){
            while(!isalpha(s[i]) && i<s.size()) i++;
            while(!isalpha(s[j]) && j>0) j--;
            if(i < j){
                swap(s[i], s[j]);                
            }
        }
        return s;
    }
};