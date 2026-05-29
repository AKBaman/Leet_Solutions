class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        dp[0] = nums[0];
    
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1){ 
                pick += dp[i-2];
            }
            int notPick = dp[i-1];
            dp[i] = Math.max(pick,notPick);
            System.out.print(dp[i] + " ");
        }

        return dp[n-1];
    }
}