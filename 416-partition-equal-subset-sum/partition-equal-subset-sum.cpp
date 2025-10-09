class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2 != 0) return false;

        int W = sum/2;
        int n  = nums.size();

        vector<vector<bool>> dp(n+1,vector<bool>(W+1));

        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }

        for(int j=1;j<W+1;j++){
            dp[0][j] = 0;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][W];
        
    } 
};