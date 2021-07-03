class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // num rows
        int n = matrix[0].size(); // num cols
        int start = 0, end = m*n-1;
        int mid, midrow, midcol;
        
        while(start<=end){
            mid = (end + start)/2;
            midrow = mid/n;
            midcol = mid%n;
            if(matrix[midrow][midcol] == target) return true;
            if(matrix[midrow][midcol] < target) start = mid +1;
            if(matrix[midrow][midcol] > target) end = mid - 1;
        }
        return false;
    }
};