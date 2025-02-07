class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map <int,int> ballmap;
        unordered_map <int,int> colormap;
        vector<int> result(queries.size());
        for(int i=0;i<queries.size();i++){
            int ball  = queries[i][0];
            int color = queries[i][1];
            
            if(ballmap.count(ball)){
                int prevcolor = ballmap[ball];
                colormap[prevcolor]--;
                if(colormap[prevcolor]==0){
                    colormap.erase(prevcolor);
                }
            }
            ballmap[ball] = color;
            colormap[color]++;

            result[i] = colormap.size();
        }   

        return result;
    }
};