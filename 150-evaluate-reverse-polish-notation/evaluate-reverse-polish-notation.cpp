class Solution {
public:
    int isSign(char ch,int a,int b){
        if(ch== '+') return a+b;
        else if(ch =='-') return a-b;
        else if(ch == '*') return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
       for(string token :  tokens){
        if(token == "+" || token == "-" || token =="*" || token == "/"){
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            st.push(isSign(token[0],a,b));
        }
        else{
            st.push(stoi(token));
        }
       }

        return st.top();
    }
};