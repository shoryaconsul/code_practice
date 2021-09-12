class Solution {
public:
    int numTrees(int n) {
        if(n<=2) return n;
        int num;
        int numTrees[n+1];
        numTrees[0] = 1;
        numTrees[1] = 1;
        for(int i=1; i<=n; i++){
            num = 0;
            for(int j=0; j<i; j++){
                num = num + numTrees[j]*numTrees[i-j-1];  // Root tree at i. Left subtree has j nodes, right subtree has i-j-1 nodes 
            }
            // cout<<i<<" "<<num<<endl;
            numTrees[i] = num;
        }
        return numTrees[n];
    }
};