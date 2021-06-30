class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> pos;
        char ch = ' ';
        int start=0, end=0;
        
        while(end<s.size()){
            while(s[end] == ch && end <s.size()) end++;
            if(end - start >=3 ){  // s[end] != ch
                vector<int> ind = {start, end-1};
                pos.push_back(ind);
            }
            if(end < s.size()){
                ch = s[end];
                start = end;
                end++;
            }
        }
        return pos;
        
    }
};