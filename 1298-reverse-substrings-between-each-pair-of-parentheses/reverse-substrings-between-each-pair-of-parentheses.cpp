class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        stack<int> st;
        for(char ch : s){
            if(ch == ')'){
                if(!st.empty()){
                    reverse(result.begin()+st.top(),result.end());
                    st.pop();
                }
            }
            else{
                if(ch == '('){
                   st.push(result.size());
                }
                else{
                    result+=ch;
                }
            }
        }

        return result;
    }
};