class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;  // s = ""
        else if(t.empty()) return false; // s!= "" and t=""
        
        if(s[0] == t[0]) return isSubsequence(s.substr(1), t.substr(1));
        else return isSubsequence(s, t.substr(1));
        
    }
};