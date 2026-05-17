class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        queue<int> q;

        vis[start] = true;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
 
            if(arr[curr] == 0) return true;

            int child1 = curr+arr[curr];
            int child2 = curr-arr[curr];
            if(child1 >= 0 && child1 < n){
                if(!vis[child1]){
                    vis[child1] = true;
                    q.push(child1);
                }
                
            }
            if(child2 >= 0 && child2 < n){
                if(!vis[child2]){
                    vis[child2] = true;
                    q.push(child2);
                }
            }
        }
        return false;
    }
};