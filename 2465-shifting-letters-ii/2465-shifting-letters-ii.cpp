class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>diff(s.size()+1,0);
        for(int i=0;i<shifts.size();i++){
            int l= shifts[i][0],r = shifts[i][1],dir = shifts[i][2];
            if(dir==1){
                diff[l]+=1;
                diff[r+1]-=1;
            }
            else{
                diff[l]-=1;
                diff[r+1]+=1;
            }
        }

        //Finding cummulative function
        for(int i=1;i<s.size();i++){
            diff[i]+=diff[i-1];
        } 

        for(int i=0;i<s.size();i++){
            s[i] = 'a' + (s[i]-'a' + (diff[i]%26 + 26)%26)%26;
        }

        return s;
    }
};