class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // unordered_map<string,int> map;
        int n = nums[0].size();
        string res="";
        for(int i=0;i<n;i++){
            if(nums[i][i] == '1'){
                res+="0";
            }
            else{
                res+="1";
            }
        }
        return res;

    }
};