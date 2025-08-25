class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int currSum = 0;
        int count = 0;
        map[0] = 1;
        
        for(int i=0;i< nums.size();i++){
            currSum+=nums[i];
            if(map.find(currSum - k) != map.end()){
                count+=map[currSum-k];
            }
            map[currSum]++;
        }

        return count;
    }
};