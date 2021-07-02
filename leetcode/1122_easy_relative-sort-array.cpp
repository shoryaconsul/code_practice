class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> num_freq;
        int i;
        for(i=0; i<arr1.size(); i++){  // hash map of arr1
            num_freq[arr1[i]] ++;
        }
        
        i = 0;
        for(int j=0; j<arr2.size(); j++){
            while(num_freq[arr2[j]]>0){
                arr1[i] = arr2[j];
                num_freq[arr2[j]]--;
                i++;
            }
        }
        
        for(auto iter: num_freq){  //iterate over all keys
            while(iter.second > 0){
                arr1[i] = iter.first;
                iter.second--;
                i++;
            }
        }

        return arr1;
    }
};