class DisjointSet{
  //rank and Parent and size vector
  
  public:
  vector<int> rank,parent,size;
  DisjointSet(int n){
    rank.resize(n+1,0);
    size.resize(n+1,1);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
      //initializing with them
      parent[i] = i;
    }
  }

  //log(n)
  //finding the ultimate parent of the node 
  int findUPar(int node){
    if(parent[node] == node){
      return node;
    }
    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u ,int v){
    int ultimatep_u = findUPar(u);
    int ultimatep_v = findUPar(v);

    if(ultimatep_u == ultimatep_v) return;

    if(rank[ultimatep_u] < rank[ultimatep_v]){
      parent[ultimatep_u] = ultimatep_v;
    }
    else if(rank[ultimatep_u] > rank[ultimatep_v]){
      parent[ultimatep_v] = ultimatep_u;
    }
    else{
      parent[ultimatep_v] = ultimatep_u;
      rank[ultimatep_u]++;
    }
    
  }
  //More logical as we are adding the size of the smaller one to the bigger 
  //makes more sense
  void unionBySize(int u ,int v){
    int ultimatep_u = findUPar(u);
    int ultimatep_v = findUPar(v);

    //if ultimate parentsa are same 
    if(ultimatep_u == ultimatep_v) return;

    //check sizes of ultimate parents
   if(size[ultimatep_u] < size[ultimatep_v]){
    parent[ultimatep_u] = ultimatep_v;
    size[ultimatep_v] += size[ultimatep_u];
   }else{
    parent[ultimatep_v] = ultimatep_u;
    size[ultimatep_u]+=size[ultimatep_v];
   }
    
  }
};

///Using Disjoint set;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }

        return cnt;
    }
};