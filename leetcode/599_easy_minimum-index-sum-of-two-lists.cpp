class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size();
        int n2 = list2.size();
        int max1 = n1, max2 = n2;
        int idx_sum = n1+n2-2;
        vector<string> res;
        for(int i=0; i<max1; i++){
            for(int j=0; j<max2; j++){
                if(list1[i] == list2[j]){
                    // cout<< i <<" "<< j<<" "<<idx_sum<<endl;
                    if(i+j < idx_sum){
                        res.clear();
                        res.push_back(list1[i]);
                        idx_sum = i + j;
                        max1 = min(n1, idx_sum+1);
                        max2 = min(n2, idx_sum+1);
                    }
                    else if(i+j == idx_sum) res.push_back(list1[i]);
                }
            }
        }
        
        return res;
    }
};