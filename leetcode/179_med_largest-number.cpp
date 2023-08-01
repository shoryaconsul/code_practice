class Solution {
public:

    static bool sort_str(const string s1, const string s2){
        return (s1 + s2) < (s2 + s1);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> nums_str (nums.size());
        for(int i=0; i < nums.size(); i++){
            nums_str[i] = to_string(nums[i]);
        }

        std::sort(nums_str.begin(), nums_str.end(), sort_str);

        string res = "";
        if(nums_str[nums.size()-1] == "0") return "0";

        for(int i=nums.size()-1; i >= 0; i--){
            // cout << nums[i] << endl;
            res = res + nums_str[i];
        }

        return res;
    }

};