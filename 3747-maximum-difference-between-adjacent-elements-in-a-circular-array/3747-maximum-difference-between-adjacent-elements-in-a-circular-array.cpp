class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n =nums.size(),diff=0;
        for(int i=0;i<n-1;i++){
            if(abs(nums[i+1] - nums[i]) >  diff){
                diff= abs(nums[i+1]-nums[i]);
            }
        }
        diff = max(diff,abs(nums[n-1]-nums[0]));
        return diff;
    }
};