class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = -1,end=0,mid,ans=0;

        for(int n : weights){
            start = max(start,n);
            end+=n;
        }

        while(start <= end){
            mid  = start + (end-start)/2;
            int sum =0,count=1;
            for(int i=0;i<weights.size();i++){
                sum+=weights[i];
                if(sum > mid){
                    sum = weights[i];
                    count++;
                }
            }
            if(count <= days){
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