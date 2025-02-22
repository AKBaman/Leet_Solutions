class Solution {
public:
    void generateSubs(vector<int> arr,int index,int n,vector<vector<int>>& ans,vector<int> temp){
        if(index==n){
            ans.push_back(temp);
            return;
        }
        generateSubs(arr,index+1,n,ans,temp);
        temp.push_back(arr[index]);
        generateSubs(arr,index+1,n,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>> ans;
        generateSubs(nums,0,n,ans,temp);

        return ans;
    }
};