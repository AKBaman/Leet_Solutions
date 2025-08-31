class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &road: roads){
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        int mod = 1e9 + 7;
        vector<long long> count(n,0);   // use long long to avoid overflow
        vector<long long> dist(n,1e15); // large value

        count[0] = 1;
        dist[0] = 0;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        q.push({0,0});

        while(!q.empty()){
            auto [time,node] = q.top();
            q.pop();

            if(time > dist[node]) continue; // skip outdated entry

            for(auto [adjNode, adjTime] : adj[node]){
                if(time + adjTime < dist[adjNode]){
                    dist[adjNode] = time + adjTime;
                    count[adjNode] = count[node]%mod;  // inherit path count
                    q.push({dist[adjNode], adjNode});
                }
                else if(time + adjTime == dist[adjNode]){
                    count[adjNode] += (count[node]%mod); // add alternative path
                }
            }
        }
        return count[n-1]%mod; // number of shortest paths from 0 to n-1
    }
};
