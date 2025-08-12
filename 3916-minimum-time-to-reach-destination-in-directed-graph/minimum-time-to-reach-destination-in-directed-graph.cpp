class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,pair<int,int>>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
            adj[u].push_back({v, {start, end}});
        }

        set<pair<int,int>> st; // {time, node}
        st.insert({0, 0});
        vector<int> dist(n, 1e9);
        dist[0] = 0;

        while (!st.empty()) {
            auto [currT, node] = *st.begin();
            st.erase(st.begin());

            for (auto& e : adj[node]) {
                int v = e.first;
                int start = e.second.first;
                int end = e.second.second;

                int nextT = max(currT, start); // wait if needed
                if (nextT <= end) {
                    if (nextT + 1 < dist[v]) {
                        auto itSet = st.find({dist[v], v});
                        if (itSet != st.end()) st.erase(itSet);
                        dist[v] = nextT + 1;
                        st.insert({dist[v], v});
                    }
                }
            }
        }

        return dist[n-1] == 1e9 ? -1 : dist[n-1];
    }
};
