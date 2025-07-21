class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int count = 1;
        for(int num : target){
            if(count > n){
                break;
            }
            ans.push_back("Push");
            while(!ans.empty() && count != num && count <= n){
                ans.push_back("Pop");
                count++;
                ans.push_back("Push");
            }
            count++;
        }

        return ans;
    }
};