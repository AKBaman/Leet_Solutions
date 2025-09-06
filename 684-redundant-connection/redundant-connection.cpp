class Disjoint{
    public:
    vector<int> parent,size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int m = findPar(u);
        int n = findPar(v);

        if(m == n) return;

        if(size[m]<size[n]){
            parent[m] = n;
            size[n] += size[m];
        }
        else{
            parent[n] = m;
            size[m]+=size[n];
        }
    }
 
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint ds(n);

        int ansU = -1,ansV =-1;
        for(vector<int>& edge :edges){
            int u = edge[0];
            int v = edge[1];

            if(ds.findPar(u) != ds.findPar(v)){
                ds.unionBySize(u,v);
            }
            else{
                ansU= u;
                ansV= v;
            }
        }

        return  {ansU,ansV};
    }
};