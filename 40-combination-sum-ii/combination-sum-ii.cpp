class Solution {
public:
    void findSet(vector<int>&arr,int index,vector<vector<int>>& ans,vector<int>& temp,int target){
        if(target==0){
            // sort(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }

        // if(index==n || target<0){
        //     return;
        // }
        // findSet(arr,index+1,n,ans,temp,target);
        // temp.push_back(arr[index]);
        // findSet(arr,index+1,n,ans,temp,target-arr[index]);
        // temp.pop_back();
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i] > target) break;
            temp.push_back(arr[i]);
            findSet(arr,i+1,ans,temp,target-arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>temp;
        findSet(candidates,0,ans,temp,target);
        return ans;
    }
};