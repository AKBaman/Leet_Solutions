class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>ans(2,0);
        vector<int>vec(n*n+1,0);
        for(vector<int> v : grid){
            for(int n : v){
                vec[n]++;
                if(vec[n]==2){
                   ans[0]=n;
                }
            }
        }
        for(int i=1;i<=n*n;i++){
            if(vec[i]==0){
                ans[1]=i;
                break;
            }
        }

        return ans;
    }
};