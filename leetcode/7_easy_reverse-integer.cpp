#include <cmath>

class Solution {
public:
    int reverse(int x) {
        int INTMAX = pow(2,31)-1;
        int INTMIN = -1*pow(2,31);
        int y = abs(x);
        int q, r, res=0;

        while(y >= 1){
            //cout << res <<endl;
            r = y%10;
            y = y/10;
            if(x > 0){
                if(res > INTMAX/10 || (res == INTMAX/10 && r > 7)){  //overflow
                    return 0;
                }
                else{
                    res = 10*res + r;
                }
            }
            else{  // x < 0
                if(res < INTMIN/10 || (res == INTMIN/10 && r > 8)){  //overflow
                    return 0;
                }
                else{
                    res = 10*res - r;
                }
            }
        }
    return res;
    }
};