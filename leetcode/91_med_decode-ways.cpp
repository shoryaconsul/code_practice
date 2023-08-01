class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int pen_ways = 0, prev_ways = 0;
        int curr_ways;

        if(s[0] == '0'){
            return 0;
        }
        else{
            curr_ways = 1;
        }

        if(n == 1) return curr_ways;
        else {
            prev_ways = curr_ways;
            pen_ways = 1;
        }

        for(int i=1; i<n; i++){
            // cout << "Conds: " << i << endl;
            // cout << (s[i-1] == '1') << " " << (s[i-1] == '2')*(s[i] <= '6') << endl;
            curr_ways = (prev_ways*(s[i] > '0')
                    + pen_ways*(s[i-1] == '1')
                    + pen_ways*(s[i-1] == '2')*(s[i] <= '6')
            );
            cout << i << " " << curr_ways << endl;
            pen_ways = prev_ways;
            prev_ways = curr_ways;
        }
        
        return curr_ways;
    }
};