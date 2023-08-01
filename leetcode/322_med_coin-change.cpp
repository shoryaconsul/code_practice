// Recurison without memoization

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(std::find(coins.begin(), coins.end(), amount) != coins.end()){
            return 1;
        }

        if(amount < 0) return -1;
        if(amount == 0) return 0;           

        int res = INT_MAX;
        int curr, impos = 0;
        for(int i=0; i<coins.size(); i++){
            curr = coinChange(coins, amount - coins[i]);
            if(curr > 0){
                res = min(res, curr + 1);
            }
            else{
                impos--;
            }
        }
        
        if(impos == -1*coins.size()) return -1;
        else return res;
    }
};


// Bottom-up DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        cout << amount <<endl;
        int numCoins[amount + 1];
        numCoins[0] = 0;
        for(int c : coins){  // initialization
            if(c <= amount) numCoins[c] = 1;
        }

        int tmp;
        for(int i=1; i <= amount; i++){
            tmp = INT_MAX;
            for(int c : coins){
                if(c <= i && numCoins[i-c] >= 0){
                    tmp = min(tmp, numCoins[i-c] + 1);
                }
            }
            
            if(tmp == INT_MAX) numCoins[i] = -1;
            else numCoins[i] = tmp;
        }

    return numCoins[amount];
    }
}

