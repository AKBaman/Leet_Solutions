class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long ans = 0,maxDiff = 0,maxElement = 0;

        for(long num : nums){
            ans  = max(ans , (maxDiff)*num);
            maxDiff = max(maxDiff, maxElement-num);
            maxElement = max(maxElement,num);
        }

        return ans;
    }
};