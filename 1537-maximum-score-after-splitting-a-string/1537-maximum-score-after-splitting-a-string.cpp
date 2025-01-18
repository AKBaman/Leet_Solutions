class Solution {
public:
    int maxScore(string s) {
        vector<int> prefix(s.size(),0);
        prefix[0] = s[0]-'0';
        for(int i=1;i<s.size();i++){
            prefix[i]=prefix[i-1] + (s[i]-'0');
        }
        int count = 0;
        int maxscore = -1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                count++;
            }
            int score = count + prefix[s.size()-1] - prefix[i];
            maxscore = max(maxscore,score);
        }
        if(count==s.size()) return s.size()-1;
        return maxscore;
    }
};