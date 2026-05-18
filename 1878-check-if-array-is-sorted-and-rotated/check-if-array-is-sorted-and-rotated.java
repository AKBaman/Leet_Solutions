class Solution {
    public boolean check(int[] nums) {
        int violet = 0,n = nums.length;
        for(int i=1;i<n;i++){
            if(nums[i-1] > nums[i]){
                violet++;
            }
        }
        if(nums[n-1] > nums[0]) violet++;
        System.out.print(violet);
        return violet <= 1;
    }

}