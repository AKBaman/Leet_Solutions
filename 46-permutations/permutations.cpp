class Solution {
public:
    void findPermut(vector<int>arr,vector<vector<int>>& ans,vector<int>& temp,vector<bool>& visited){
        if(temp.size() == arr.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<arr.size();i++){
            if(visited[i] == 0){
                visited[i] = 1;
                temp.push_back(arr[i]);
                findPermut(arr,ans,temp,visited);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        vector<bool>visited (nums.size(),0);
        findPermut(nums,ans,temp,visited);
        return ans;
    }
};