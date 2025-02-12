class Solution {
public:
    string removeOccurrences(string s, string part) {
        // int res = -1;
        // while((res = s.find(part,res+1)) != string::npos){
        //     s.erase(s.begin() + res,s.begin() + res + part.size());
        //     res=-1;
        // }
        // return s;

        string ans;
        int m = part.size();
        for(char c : s){
            ans.push_back(c);

            if(ans.size() >= m && ans.substr(ans.size() - m) == part){
                ans.erase(ans.size() - m);
            }
        }

        return ans;
    }     
};