class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        map<char,int> dict;
        for(auto i : s){
            if(dict.find(i) != dict.end()) dict[i]++;
            else dict[i] = 1;
        }

        for(auto j: t){
            if(dict.find(j) != dict.end()){
                if(dict[j] > 0) dict[j]--;
                else return false;
            }
            else return false;
        }

        return true;
    }
};