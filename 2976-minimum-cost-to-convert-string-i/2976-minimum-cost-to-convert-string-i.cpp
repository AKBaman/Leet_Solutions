class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.size() != target.size()) return -1;
        long long INF = 1e18;

        vector<vector<long long>> dist(26,vector<long long>(26,INF));
        for(int i=0;i<26;i++){
            dist[i][i] = 0;
        }

        for(int i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a'] = min((long long)cost[i],dist[original[i]-'a']    [changed[i]-'a']);
        }

        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][via] != INF && dist[via][j] != INF){
                        dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(dist[source[i]-'a'][target[i]-'a'] == INF){
                return -1;
            }
            ans+=dist[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
};