class Disjoint{
    public:
    vector<int> parent,size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        iota(parent.begin(),parent.end(),0);
    } 

    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u,int v){
        int m = find(u);
        int n = find(v);

        if(m == n) return;

        if(size[m] < size[n]){
            parent[m] = n;
            size[n] += size[m];
        }
        else{
            parent[n] = m;
            size[m] += size[n];
        }
    }
};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string,int> map;
         
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(map.find(mail) == map.end()){
                    map[mail] = i;
                }
                else{
                    ds.unionBySize(i,ds.find(map[mail]));
                }
            }
            
        }

        vector<vector<string>> merge(n);

        for(auto it : map){
            string mail = it.first;
            int node = ds.find(it.second);
            merge[node].push_back(mail); 
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merge[i].size() == 0) continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};