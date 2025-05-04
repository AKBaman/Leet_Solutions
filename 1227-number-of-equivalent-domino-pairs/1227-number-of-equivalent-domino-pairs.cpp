class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0,n = dominoes.size();

        for(int i=0;i<n;i++){
            int a = dominoes[i][0],b=dominoes[i][1];
            for(int j=i+1;j<n;j++){
                int c = dominoes[j][0],d=dominoes[j][1];

                if((a==c && b==d) || (a==d && b==c)){
                    count++;
                }
            }
        }

        return count;
        
    }
};