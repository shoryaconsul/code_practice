class Solution {
public:
    string strtolower(string s){
        string res;
        for(int i=0; i<s.size(); i++){
            res = res + (char) tolower(s[i]);
        }
        return res;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> word_freq;
        int start = 0;
        string word, word_max, banned_word;
        int count_max = 0, pos;
        string punct = "!?,;.";
        punct = punct + " " + "\'";
        
        while(paragraph.find_first_of(punct, start) != string::npos){
            pos = paragraph.find_first_of(punct, start);
            if(pos != start){
                word = paragraph.substr(start, pos-start);
                word = strtolower(word);
                word_freq[word] = word_freq[word] + 1;
                // cout<<pos<< " "<<word<<endl;
            }
            start = pos+1;
        }
        if(start < paragraph.size()){  // last word
            word = paragraph.substr(start);
            word = strtolower(word);
            word_freq[word] = word_freq[word] + 1;
        }
        
        for(int i=0; i<banned.size(); i++){ // setting counts for banned words to 0
            banned_word = banned[i];
            word_freq[banned_word] = 0;
        }
        
        for(auto iter : word_freq){
            if(iter.second > count_max){
                count_max = iter.second;
                word_max = iter.first;
            }
        } 
        
        return word_max;
    }
};