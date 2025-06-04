class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start = -1,end=0,mid,ans=-1;

        for(int n : nums){
            start = max(n,start);
            end+=n;
        }
        
        while(start <= end){
            mid = start + (end-start)/2;
            int sum = 0,count=1;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(sum > mid){
                    sum = nums[i];
                    count++;
                }
            }
            if(count <= k){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};