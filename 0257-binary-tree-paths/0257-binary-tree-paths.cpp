/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void path(TreeNode* root,vector<vector<int>>& res,vector<int>& ans){
        if(!root) return;

        ans.push_back(root->val);

        if(!root->left && !root->right){
            res.push_back(ans);
            ans.pop_back();
            return;
        }

        path(root->left,res,ans);
        path(root->right,res,ans);
        ans.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>>ans;
        vector<int> temp;

        vector<string> result;

        path(root,ans,temp);

        for(vector<int> res: ans){
            string s ="";
            for(int i=0;i<res.size()-1;i++){
                s+=to_string(res[i]);
                s+="->";
            }
            s+=to_string(res[res.size()-1]);
            result.push_back(s);
        }

        return result;
    }
};