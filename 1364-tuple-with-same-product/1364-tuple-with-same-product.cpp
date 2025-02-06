class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map <int ,int> ump;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ump[nums[i]*nums[j]]++;
            }
        }
        int count=0;
        for(auto x : ump){
            int n = x.second;
            if(n>=1){
                count = count + (n)*(n-1)*4;
            }
        }
        return count;
    }
};