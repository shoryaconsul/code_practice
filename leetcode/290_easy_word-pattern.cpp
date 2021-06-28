class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream reads(s);
        string w;
        while(getline(reads, w, ' ')){
            words.push_back(w);
        }
        if(words.size() != pattern.length()) return false;  // mismatch in pattern and # words

        map<char, int> pattern_idx;
        map<string, int> word_idx;
        for(int i=0; i<pattern.length(); i++){
            char p = pattern[i];
            w = words[i];
            if(pattern_idx[p] == 0 && word_idx[w] == 0){  // first occurrence
                pattern_idx[p] = i+1;
                word_idx[w]  = i+1;
            }
            else{
                if(pattern_idx[p] != word_idx[w]) return false;
            }
        }
        return true;
    }
};