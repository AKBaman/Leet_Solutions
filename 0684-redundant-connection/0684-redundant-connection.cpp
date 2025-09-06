class Solution {
public:
    vector<int> parent;

    int findPar(int node){
        return parent[node] == node ? node : parent[node] = findPar(parent[node]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);

        for(vector<int>& e : edges){
            int u = findPar(e[0]);
            int v = findPar(e[1]);
            if(u == v){
                return e;
            }

            parent[u] = v;
        }

        return {};
    }
};