class Solution {
public:
    // {1,2,3,4,2} ==> duplicate waale case ko avoid karne ke liye kisi ek NSR or NSL me arr[st.top()] >= arr[i] st.pop() kr lenge yaani ek case me duplicate ko include kr lenge 
    vector<int> getNSL(vector<int>& arr,int n){
        vector<int> res(n);

        stack<int> st; //indices for Next smaller element to the left

        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i] =-1;
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

                res[i] = st.empty() ? -1 : st.top(); 
            }

            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>arr,int n){
        vector<int> res(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i] = n;
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

                res[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);

        int M = 1e9+7;
        long long sum = 0;

       

        for(int i=0;i<n;i++){
            long long left = i - NSL[i]; //left ke saare subarrays
            long long right = NSR[i] - i; //right ke saare subarrays

            long long countArrays = left*right;

            long long totalSum = arr[i]*countArrays;

            sum = (sum + totalSum) %M;
        }


        return sum;

    }
};