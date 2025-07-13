class Solution {
public:
    bool isSign(string ch){
        return ch == "+" || ch == "-" || ch == "*" || ch == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i=0;i<n;i++){
            if(!isSign(tokens[i])){
                st.push(stoi(tokens[i]));
                cout<<st.top()<<endl;
            }
            else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int result = 0;
                
                if(tokens[i] == "+"){
                    result = a + b;
                    st.push(result);
                }
                else if(tokens[i] == "-"){
                    result = a - b;
                    st.push(result);
                }
                else if(tokens[i] == "*"){
                    result = a*b;
                    st.push(result);
                }
                else{
                    result = a/b;
                    st.push(result);
                }
                cout<<st.top()<<" ";
            }
        }

        return st.top();
    }
};