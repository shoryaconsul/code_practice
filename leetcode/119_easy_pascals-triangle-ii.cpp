class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row_curr = {1};
        int prev_val, curr_val;

        for(int i=1; i <= rowIndex; i++){
            curr_val = row_curr[0];

            for(int j=1; j < i; j++){
                prev_val = curr_val;
                curr_val = row_curr[j];
                row_curr[j] = prev_val + curr_val;
            }
            row_curr.push_back(1);
        }

        return row_curr;
    }
};