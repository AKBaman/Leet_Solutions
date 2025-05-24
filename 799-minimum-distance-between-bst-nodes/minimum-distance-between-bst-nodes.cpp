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
    void inorder(TreeNode* root,int& ans,int& prev){
        if(!root) return;
        inorder(root->left,ans,prev);
        if(prev!=INT_MIN){
            ans= min(ans,root->val-prev);
        }
        prev = root->val;
        inorder(root->right,ans,prev);
    }

    int minDiffInBST(TreeNode* root) {
        int prev =INT_MIN;
        int ans = INT_MAX;

        inorder(root,ans,prev);
        return ans;
    }
};