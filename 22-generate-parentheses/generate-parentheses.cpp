class Solution {
public:

    void generate(int n,int left,int right,vector<string>& ans,string &temp){

        if(left + right == 2*n){
            ans.push_back(temp);
            return;
        }

        if(left < n){
            temp.push_back('(');
            generate(n,left+1,right,ans,temp);
            temp.pop_back();
        }
        if(right < left){
            temp.push_back(')');
            generate(n,left,right+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int left=0,right=0;
        generate(n,left,right,ans,temp);
        return ans;
    }
};