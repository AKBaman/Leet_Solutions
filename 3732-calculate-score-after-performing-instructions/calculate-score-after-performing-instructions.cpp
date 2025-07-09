class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score = 0;
        vector<bool> vis(values.size(),0);
        for(int i=0;i<values.size();){
            if(!vis[i] || i<0){
                vis[i]=1;
                if(instructions[i] == "jump"){
                    i+=values[i];
                }
                else{
                    score+=values[i++];
                }
            }
            else{
                return score;
            }
        }
        return score;
    }   
};