class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> queue;
        for(int n :  nums){
            queue.emplace(n);
        }
        while(--k){
            queue.pop();
        }
        return queue.top();
    }
};