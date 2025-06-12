class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> map;

        for(auto n : nums){
            map[n]++;
        }
        int n = nums.size();
        n/=3;
        for(auto& it : map){
            if(it.second>n){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};