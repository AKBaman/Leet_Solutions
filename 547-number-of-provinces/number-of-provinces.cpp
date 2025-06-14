class Solution {
private:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=1;

        for(int j = 0;j<adj.size();j++){
            if(adj[node][j] == 1 && !vis[j]){
                dfs(j,adj,vis);
            }
        }
    }
public:

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        int count=0;
        vector<bool>vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};