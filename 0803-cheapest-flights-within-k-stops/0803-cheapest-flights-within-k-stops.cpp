class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            adj[u].push_back({v,price});
        }
    //    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    queue<pair<int,pair<int,int>>> pq;

        pq.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;

       while(!pq.empty()){
        // auto it = pq.top();
        auto it = pq.front();
        int stop =  it.first;
        int node =  it.second.first;
        int price = it.second.second;
        pq.pop();
        if(stop<=k){
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjNodePrice = it.second;
                if(price + adjNodePrice < dist[adjNode]){
                    dist[adjNode] = price + adjNodePrice;
                    pq.push({stop+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        else{
            continue;
        }
       }
        return (dist[dst] == 1e9) ? -1 : dist[dst];;
    }
};