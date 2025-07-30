class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n == k) return "0";


        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && num[i] < st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
         while(k > 0){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
       
        int i = ans.size()-1;
        while(i>=0){
            if(ans[i] == '0'){
                ans[i] = '#';
                i--;
            }
            else{
                break;
            }
        }
        ans.erase(remove(ans.begin(),ans.end(),'#'),ans.end());

        if(ans.empty()) return "0";

        reverse(ans.begin() ,ans.end());
        return ans;
    }
};