class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr = nums;
        vector<int> ans (nums.size()*2);
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]);
        }
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i] =-1;
            }
             else{
                while(!st.empty() && st.top() <= arr[i]) st.pop();
                ans[i] = st.empty() ?  -1: st.top();
            }
            st.push(arr[i]);
        }

        for(int i=0;i<nums.size();i++){
            cout<<ans[i];
            nums[i] = ans[i];
    
        }

        return nums;
    }
};