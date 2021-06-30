class Solution {
public:
    int binaryGap(int n) {
        int start=-1, end=0, i=0, b, max_dist=0;
        while(n >= 1){
            b = n%2;
            n = n >> 1;
            cout<<i<<" "<<b<<" "<<n<<" "<<max_dist<<endl;
            if(b==1){
                if(start == -1){
                    start = i;
                    end = i;
                }
                else{
                    start = end;
                    end = i;
                    if(end - start > max_dist) max_dist = end-start;
                }
            }
            i++;
        }
        return max_dist;
    }
};