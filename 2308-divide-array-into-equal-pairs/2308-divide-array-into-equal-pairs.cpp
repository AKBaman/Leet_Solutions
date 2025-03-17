class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int  n = nums.size();
        int pairs = n/2;
        unordered_map<int,int> map;
        for(int n : nums){
            map[n]++;
        }

        for(auto &it : map){
            if(it.second%2!=0){
                return false;
            }
        }

        return true;
    }
};