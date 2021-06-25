class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> row1{ 1 };
        vector<vector<int>> res(numRows);
        res[0] = row1;
        for(int i=1; i<numRows; i++){
            vector<int> row_prev(i);
            row_prev = res[i-1];
            vector<int> row_curr(i+1);
            row_curr[0] = 1;  // first element is always 1
            row_curr[i] = 1; // last element is always 1
            for(int j=1; j<i; j++){
                row_curr[j] = row_prev[j-1] + row_prev[j];
            }
            res[i] = row_curr;
        }
        return res;
    }
};