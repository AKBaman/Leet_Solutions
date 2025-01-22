class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> uniq;
        int res=0;
        for(char c : s){
            uniq.insert(c);
        }

        for(char c : uniq){
            int start  = s.find(c);
            int end  = s.rfind(c);

            if(start < end){
                unordered_set<char> set;
                for(int i = start+1;i<end;i++){
                    set.insert(s[i]);
                }
                res += set.size();
            }
            
        }
        return res;
    }
};