class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int> que;
        unordered_set<int> set;

        for(int i=0;i<nums.size();i++){
            que.push(nums[i]);
        }

        if(que.empty()) return 0;

        int maxCount = 0,prev = que.top(),count=1;
        set.insert(prev);
        que.pop();

        while(!que.empty()){
            int curr = que.top(); que.pop();

            if(set.count(curr)) continue; // skip duplicates

            set.insert(curr);
            if(curr + 1 == prev){
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 1; // restart count
            }
            prev = curr;
        }
        maxCount = max(maxCount, count); // final update
        return maxCount;
    }
};