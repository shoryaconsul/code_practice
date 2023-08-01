class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> pal(n, vector<bool> (n, false));
        for(int i=0; i<n; i++){  // singletons are palindromes
            pal[i][i] = true;
        }

        int max_len = 1;
        int max_start = 0;

        for(int i=0; i<n-1; i++){  // checking doubles
            pal[i][i+1] = (s[i] == s[i+1]);
            if(pal[i][i+1]){
                max_start = i;
                max_len = 2;
            }
        }

        for(int d=2; d<n; d++){
            for(int i=0; i<n-d; i++){
                pal[i][i+d] = (s[i] == s[i+d]) && pal[i+1][i+d-1];
                if(pal[i][i+d]){
                    if(max_len <= d){
                        max_len = d + 1;
                        max_start = i;
                    }
                }
            }
        }

        // cout<< max_start <<" "<<max_len<<endl;
        return s.substr(max_start, max_len);
    }
};