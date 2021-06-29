class Solution {
public:
    string reverseWords(string s) {
        istringstream str(s);
        string res = "", word;
        int n;
        while(str >> word){
            n = word.size();
            for(int i=0; i<n/2; i++){
                swap(word[i], word[n-i-1]);
            }
            res = res + word + " ";
        }
        return res.substr(0, res.size()-1);
    }
};