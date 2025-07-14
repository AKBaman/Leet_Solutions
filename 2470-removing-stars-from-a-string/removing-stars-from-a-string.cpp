class Solution {
public:
    string removeStars(string s) {
        string ans="";

        for(char ch : s){
            if(ch == '*' && ans!=""){
                ans.pop_back();
            }
            else{
                ans+=ch;
            }
        }

        return ans;
    }
};