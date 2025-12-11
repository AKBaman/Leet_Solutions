class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int i=0;
        for(auto it : set){
            nums[i++]  = it;
        }

        return set.size();
        
    }
};