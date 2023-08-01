class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() == 1) return strs[0];

        int slen = strs[0].length();
        bool common;
        string res = "";
        for(int j=0; j<slen; j++){
            for(int i=1; i < strs.size(); i++){
                if(j >= strs[i].length()) return res;
                if(strs[i][j] != strs[0][j]) return res;
            }
            res = res + strs[0][j];
        }

        return res;
    }
};