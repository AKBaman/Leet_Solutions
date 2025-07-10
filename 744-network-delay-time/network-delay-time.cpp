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

       //using set
       //set{distance ,node}
       set<pair<int,int>> set;
       set.insert({0,k-1});

       while(!set.empty()){
            auto it  = *(set.begin());
            int dis  = it.first;
            int node = it.second;
            set.erase(set.begin());

            for(auto it : adj[node]){

                int edgeWeight = it.first;
                int adjNode = it.second;

                if(edgeWeight + dis < dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        set.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]= edgeWeight + dis;
                    set.insert({dist[adjNode],adjNode});
                }
            }
       }
       int delay = -1;
       for(int it : dist){
            if(it == 1e9) return -1;
            delay = max(delay,it);
       }
        return delay;
    }
};