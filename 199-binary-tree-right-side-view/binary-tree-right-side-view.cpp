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
    void rightView(TreeNode* root,vector<int>& ans,int curr){
        if(!root) return;
        if(curr == ans.size()){
            ans.push_back(root->val);
        }
        rightView(root->right,ans,curr+1);
        rightView(root->left,ans,curr+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int currLevel = 0;
        rightView(root,ans,currLevel);
        return ans;
    }
};