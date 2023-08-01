class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res = {0};
        int odd, quot = 0;

        for(int i=1; i <= n; i++){
            odd = i % 2;  // 1 if odd
            quot = (i - odd)/2;
            res.push_back(odd + res[quot]);
        }

        return res;
    }
};