class Solution {
    public int removeDuplicates(int[] nums) {
        int unique,n=nums.length,count=1;
        unique = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]!=unique){
                unique = nums[i];
                nums[count++] = unique;
            }
        }
        return count;
        
    }
}