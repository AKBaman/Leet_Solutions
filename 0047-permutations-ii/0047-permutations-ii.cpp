class Solution {
public:

    void Permut(vector<int>&arr,vector<vector<int>>& ans,int index){
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }
        unordered_map<int,bool>map;
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[index]) continue; 
            if(map[arr[i]]==0){
                swap(arr[i],arr[index]);
                Permut(arr,ans,index+1);
                swap(arr[i],arr[index]);
                map[arr[i]]=1;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        Permut(nums,ans,0);
        return ans;
    }
};