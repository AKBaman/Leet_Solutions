class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int reach = 0;
        for(int i=0;i<n;i++){
            if(i > reach) return false;
            reach = Math.max(i+nums[i],reach);
        }

        return true;
    }
}