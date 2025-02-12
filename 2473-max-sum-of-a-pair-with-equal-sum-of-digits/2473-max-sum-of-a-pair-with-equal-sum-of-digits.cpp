class Solution {
public:
    int digitSum(int n){
        int sum =0;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxSum = -1;
        for(int n : nums){
            if(map.count(digitSum(n))){
                maxSum = max(maxSum,map[digitSum(n)] + n);
            }
            map[digitSum(n)] = max(map[digitSum(n)],n);
        }
        
        return maxSum;
    }
};