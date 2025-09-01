class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //use Flyod Warshell for min distance
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] != 1e9 && dist[via][j] != 1e9){
                        if(dist[i][via] + dist[via][j] < dist[i][j]){
                            dist[i][j] = dist[i][via] + dist[via][j];
                        }
                    }
                }
            }
        }
        int maxCity = n+1;
        int city = -1;
    
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= maxCity){
                maxCity = count;
                city = i;
            }
        }

        return city;
    }
};