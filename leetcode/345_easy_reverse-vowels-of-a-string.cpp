class Solution {
public:
    
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1, first_idx, last_idx;
        
        while(i < j){
            first_idx = s.find_first_of("aeiouAEIOU", i);
            last_idx = s.find_last_of("aeiouAEIOU", j);
            if(first_idx < last_idx){
                swap(s[first_idx], s[last_idx]);
            }
            i = first_idx + 1;  // advance loop
            j = last_idx - 1;
        }
        
        return s;
    }
};