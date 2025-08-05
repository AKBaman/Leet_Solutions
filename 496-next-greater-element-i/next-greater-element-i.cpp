class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n=nums2.size();
        vector<int> NLR(n,-1);
        stack<int> st;
        map<int,int> map;

        for(int i=n-1;i>=0;i--){
            map[nums2[i]] = i;
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                st.pop();
            }
            
            if(!st.empty()){
                NLR[i] = nums2[st.top()];
            }
            st.push(i);
        }

        vector<int> ans(m);
        for(int i=0;i<m;i++){
            ans[i] = NLR[map[nums1[i]]];
        }

        return ans;
    }
};