class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp[100000];
        int n = nums.size();
        for(int i=0;i<n;i++){
            // if(i+k<=n){
            //     temp[i+k] = nums[i];
            // }
            // else{
            //     temp[i+k-n] = nums[i];
            // }
            int val = (i+k)%n;
            temp[val] = nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
    }
};