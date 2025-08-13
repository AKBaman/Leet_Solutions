class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int srcx = 0,srcy = 0;
        int desx = n-1,desy = n-1;
        if(grid[srcx][srcy] == 1 || grid[desx][desy] == 1) return -1;
        if(srcx==desx || srcy == desy) return 1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[srcx][srcy] = 0;
        queue<pair<int ,pair<int,int>>> q;
        q.push({1 ,{0,0}});
        vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> col = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            auto it  = q.front();
            int dis  = it.first;
            int noder = it.second.first;
            int nodec = it.second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow = noder + row[i];
                int ncol = nodec + col[i];
                if((nrow >=0 && nrow<=n-1) &&(ncol>=0 && ncol<=n-1) && (grid[nrow][ncol] == 0)){
                    if(dis + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dis + 1;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            } 
        }
        return dist[desx][desy] == 1e9 ? -1 : dist[desx][desy];
    }
};