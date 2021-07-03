class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        vector<vector<int>> sums(grid.begin(), grid.end());
        for(int i=0; i<numRows; i++){  // dynamic programming
            for(int j=0; j<numCols; j++){
                if(i==0 && j==0) ;  // pass
                else if(i==0){  // j > 0
                    sums[i][j] = sums[i][j-1] + grid[i][j];
                }
                else if(j==0){  // i > 0
                    sums[i][j] = sums[i-1][j] + grid[i][j];
                }
                else{  // i > 0, j > 0
                    sums[i][j] = min(sums[i][j-1], sums[i-1][j]) + grid[i][j];
                }
            }
        }
        return sums[numRows-1][numCols-1];
    }
    
};