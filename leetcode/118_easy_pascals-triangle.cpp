class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> row0 = {1};
        res.push_back(row0);

        for(int i=1; i<numRows; i++){ // i = row number - 1
            vector<int> row = {1};
            for(int j=1; j<i; j++){  // populating row
                row.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            row.push_back(1); 
            res.push_back(row);
        }

        return res;
    }
};