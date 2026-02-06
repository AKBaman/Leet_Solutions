class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size()-1,i=0,k=0;
        vector<int> arr(n+1,0);
        while(i<=n){
            if(nums[i]!=0){
                arr[k++] = nums[i];
            }
            i++;
        }
        nums = arr;
    }
};