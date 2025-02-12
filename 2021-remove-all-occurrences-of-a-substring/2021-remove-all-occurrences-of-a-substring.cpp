class Solution {
public:
    string removeOccurrences(string s, string part) {
        int res = -1;
        while((res = s.find(part,res+1)) != string::npos){
            s.erase(s.begin() + res,s.begin() + res + part.size());
            res=-1;
        }
        return s;
    }     
};