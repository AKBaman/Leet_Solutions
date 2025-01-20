class Solution {
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool isString(const string &s){
        return isVowel(s[0]) && isVowel(s[s.size()-1]);
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n,0);
        
        prefix[0] = isString(words[0]);

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + isString(words[i]);
        }

        vector<int>ans(queries.size(),0);

        for(int i=0;i<queries.size();i++){
            int l = queries[i][0],r=queries[i][1];
            ans[i] = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
        }

        return ans;
    }
};