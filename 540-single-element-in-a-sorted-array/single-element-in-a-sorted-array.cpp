class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans=-1;
        for(int n : nums){
            map[n]++;
        }

        for(auto it : map){
            if(it.second == 1){
                ans = it.first;
                break;
            }
        }

        return ans;
    }
};