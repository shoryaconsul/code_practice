class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        vector<int> tmp;
        int start, end;
        
        sort(intervals.begin(), intervals.end(), 
            [] (vector<int> i1, vector<int> i2) -> bool{
                return i1[0] <i2[0];
                });  // sort intervals in ascending order of start
        
        start = intervals[0][0];
        end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] > end){  // disjoint interval
                vector<int> tmp {start, end};
                merged.push_back(tmp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else{  // extend merged interval
                end = max(end, intervals[i][1]);
            }
        }
        vector<int> last {start, end};
        merged.push_back(last);
        return merged;
    }
};