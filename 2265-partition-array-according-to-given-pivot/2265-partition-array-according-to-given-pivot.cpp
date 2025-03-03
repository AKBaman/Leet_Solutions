class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
         vector<int> ans(nums.size(),0);
        int idx = 0;
        for(int i : nums){
            if(i < pivot){
                ans[idx++] = i;
            }
        }

        for(int i: nums){
            if(i == pivot){
                ans[idx++] = i;
            }
        }

        for(int i : nums){
            if(i > pivot){
                ans[idx++] = i;
            }
        }

        return ans;
    }
};