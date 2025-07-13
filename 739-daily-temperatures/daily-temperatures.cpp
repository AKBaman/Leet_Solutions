class Solution {
public:
    vector<int> getNLR(vector<int>& arr,int n){
        vector<int> res(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i] = 0;
            }
            else{
                while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
                res[i] = st.empty() ? 0 : st.top() - i;
            }
            st.push(i);
        }

        return res;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> NLR = getNLR(temperatures,n);

        return NLR;
    }
};