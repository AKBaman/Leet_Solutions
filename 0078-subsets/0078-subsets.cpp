class Solution {
public:
    void generateSubs(vector<int> arr,int index,int n,vector<vector<int>>& ans,vector<int>& temp){
        if(index==n){
            ans.push_back(temp);
            return;
        }
        //Not Included
        generateSubs(arr,index+1,n,ans,temp);
        //included
        temp.push_back(arr[index]);
        generateSubs(arr,index+1,n,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>> ans;
        generateSubs(nums,0,n,ans,temp);

        return ans;
    }
};