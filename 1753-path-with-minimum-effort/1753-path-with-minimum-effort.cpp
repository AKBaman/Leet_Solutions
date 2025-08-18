class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(),cols = heights[0].size();
        vector<vector<int>> dis(rows,(vector<int>(cols,1e9)));
        // priority_queue<
        // pair<int,pair<int,int>>,
        // vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        queue<pair<int,pair<int,int>>> pq;
        dis[0][0] = 0;
        pq.push({0,{0,0}});

        vector<int> rowv={0, 0, 1, -1};
        vector<int> colv={1, -1, 0, 0};

        while(!pq.empty()){
            // auto it  = pq.top();
            auto it = pq.front();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow = row + rowv[i];
                int ncol = col + colv[i];
                if(nrow >=0 && nrow <rows && ncol >=0 && ncol <cols){
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]),diff);
                    if(newEffort < dis[nrow][ncol]){
                        dis[nrow][ncol] = newEffort;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }

        return dis[rows-1][cols-1]; 
    }
};