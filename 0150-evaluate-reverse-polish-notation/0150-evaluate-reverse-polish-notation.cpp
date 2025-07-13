class Solution {
public:
    int applyOP(int a , int b, char token){
        if(token== '+') return a+b;
        else if(token=='-')return a-b;
        else if(token =='*')return a*b ;
        else return a/b;
        }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string token : tokens){
            if(token =="+" || token=="-" || token=="*" || token == "/"){
                int b=st.top();
                st.pop();
                int a= st.top();
                st.pop();

                st.push(applyOP(a,b,token[0]));
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};