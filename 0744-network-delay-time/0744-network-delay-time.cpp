class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adjacency list

        vector<vector<pair<int,int>>> adj(n);
        for(auto time : times){
            int u = time[0]-1;
            int v = time[1]-1;
            int w = time[2];

            adj[u].push_back({w,v});
        }

        vector<int> dist(n,1e9);
        dist[k-1] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();

            for(auto it : adj[node]){
                int edgeWeight = it.first;
                int adjNode = it.second;

                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] =  dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int maxDelay = 0;
        for(auto it : dist){
           if(it==1e9){
            return -1;
           }
           else{
            maxDelay = max(maxDelay,it);
           }
        }
        return maxDelay;
    }
};