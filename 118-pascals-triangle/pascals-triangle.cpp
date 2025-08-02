class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> num;
            for(int j=0;j<i+1;j++){
                if(j == 0 || j==i){
                   num.push_back(1);
                }else{
                    num.push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            res.push_back(num);
        }
        return res;
    }
};