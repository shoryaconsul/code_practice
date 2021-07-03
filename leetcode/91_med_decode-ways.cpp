class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways (s.size() + 1);
        ways[s.size()] = 1;
        if(s[s.size()-1] == '0') ways[s.size()-1] = 0;
        else ways[s.size()-1] = 1;
        
        int digit, digit_next;

        for(int i=s.size()-2; i>=0; i--){
            digit = (int) s[i] - '0';
            digit_next = (int) s[i+1] - '0';
            if(digit > 2) ways[i] = ways[i+1];
            else if(digit == 2 && digit_next > 6) ways[i] = ways[i+1];
            else if(digit == 0) ways[i] = 0;  // 0 cannot be read alone
            else{  // s[i], s[i+1] can be read two ways
                ways[i] = ways[i+1] + ways[i+2];
            }
            // cout<<digit << " "<<digit_next << " "<< i<<" "<<ways[i]<<endl;
        }
        return ways[0];
    }
};