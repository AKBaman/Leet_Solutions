class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int> set;

        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    set.insert(i);
                }
            }
        }

       while(!st.empty()){
        set.insert(st.top());
        st.pop();
       }

        string ans = "";
        for(int i=0;i<s.size();i++){
            if(set.count(i)) continue;
            ans+=s[i];
        }
        return ans;
    }
};