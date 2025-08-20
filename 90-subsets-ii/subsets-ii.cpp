class Solution {
public:
    void findSubset(int index,vector<int>& nums,vector<int>&temp,vector<vector<int>>& ans){
        ans.push_back(temp);
       for(int i=index;i<nums.size();i++){
        if(i!=index && nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        findSubset(i+1,nums,temp,ans);
        temp.pop_back();
       }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        findSubset(0,nums,temp,ans);
        return ans;
    }
};