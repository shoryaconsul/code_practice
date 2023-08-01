class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string prev = "1";
        string curr = "";
        for(int i=1; i<n; i++){
            int begin = 0, end = 0;
            char curr_d = prev[0];
            // cout << "LAST: " << prev << endl;

            while(end < prev.length()){
                while(prev[end] == curr_d){
                    end++;
                    if(end == prev.length()) break;
                }
                curr = curr + to_string(end - begin) + curr_d;
                begin = end;
                curr_d = prev[begin];
            }
            // cout << i << " " << curr << endl;

            prev = curr;
            curr = "";
        }

        return prev;
    }
};