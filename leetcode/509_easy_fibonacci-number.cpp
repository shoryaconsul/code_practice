class Solution {
public:
    int fib(int n) {
        if (n == 0 | n == 1){
            return n;
        }

        int penul = 0;
        int prev = 1;
        int curr;
        for(int i=2; i <=n; i++){
            curr = prev + penul;
            penul = prev;
            prev = curr;
        }

        return curr;
    }
};