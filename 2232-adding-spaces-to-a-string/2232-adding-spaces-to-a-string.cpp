class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        string ans="";
        int i=0,j=0;
        while(j<n){
            ans.append(s.begin()+i,s.begin()+spaces[j]);
            ans+=" ";
            i=spaces[j];
            j++;
        }
        ans.append(s.begin()+i,s.end());
        return ans;

    }
};