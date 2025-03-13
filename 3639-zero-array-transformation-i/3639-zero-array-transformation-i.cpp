class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        ///diffence array approach
        vector<int> diffArr(nums.size()+1,0);
        //Take a diffArr array in which left += val ,right + 1 += -val. //val =1(here)
        for(int i=0;i<queries.size();i++){
            int left  = queries[i][0];
            diffArr[left]+=1;
            int right = queries[i][1];
            diffArr[right + 1]-=1;
        }
        //Take cummulative or prefix sum
        for(int i=1;i<diffArr.size();i++){
            diffArr[i]+=diffArr[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] > diffArr[i]) return false;
        }

        return true;
    }
};