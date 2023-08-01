class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int tot_cost[n][3];
        for(int j=0; j<3; j++){
            tot_cost[0][j] = costs[0][j];
        }

        for (int i=1; i<n; i++){
            tot_cost[i][0] = min(tot_cost[i-1][1], tot_cost[i-1][2]) + costs[i][0];
            tot_cost[i][1] = min(tot_cost[i-1][0], tot_cost[i-1][2]) + costs[i][1];
            tot_cost[i][2] = min(tot_cost[i-1][1], tot_cost[i-1][0]) + costs[i][2];
        }

    return min({tot_cost[n-1][0], 
                tot_cost[n-1][1],
                tot_cost[n-1][2]});
    }
};