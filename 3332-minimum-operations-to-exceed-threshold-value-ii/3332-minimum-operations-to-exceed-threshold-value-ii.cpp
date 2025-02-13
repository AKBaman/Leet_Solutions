class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long ,vector<long long>,greater<long long>> q;
        //Heap Created
        for(int n : nums){
            q.emplace(n);
        }
        int count=0;
        //Operations
        while(q.top()<k){
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            q.push(x*2 + y);
            count++;
        }

        return count;
    }
};