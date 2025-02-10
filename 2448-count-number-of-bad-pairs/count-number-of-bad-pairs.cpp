class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        long long int  Total_pairs = 1LL*n*(n-1)/2;
        long long int count= 0;
        for(int i=0;i<n;i++){
            mp[nums[i]-i]++;
        }
        
        for(auto &i : mp){
            int id = i.second;
            if(id > 1){
                count+=(1LL*(id)*(id-1)/2);
            }
        }
        return Total_pairs - count;
        
    }
};