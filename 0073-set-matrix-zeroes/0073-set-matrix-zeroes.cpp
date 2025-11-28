class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> zero;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    zero.push_back({i,j});
                }
            }
        }

        for(int i=0;i<zero.size();i++){
            int row= zero[i].first;
            int col= zero[i].second;

            for(int j=0;j<n;j++){
                matrix[row][j] = 0;
            }
            for(int k=0;k<m;k++){
                matrix[k][col] = 0; 
            }
        }
    }
};