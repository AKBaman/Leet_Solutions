class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int m = nums1.size(),n=nums2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i][0] == nums2[j][0]){
                int val=nums1[i][1]+nums2[j][1];
                nums1[i][1] =val;
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else{
                if(nums1[i][0] < nums2[j][0]){
                    ans.push_back(nums1[i]);
                    i++;
                }
                else{
                    ans.push_back(nums2[j]);
                    j++;
                }
            }
        }
            
        for( ;i<m;i++){
            ans.push_back(nums1[i]);
        }

        for( ;j<n;j++){
            ans.push_back(nums2[j]);
        }
        return ans;
    }
};