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
    int check(TreeNode* root){
        if(!root) return 0;

        int lh = check(root->left);
        int rh = check(root->right);

        if(lh==-1|| rh==-1 ||abs(lh-rh) > 1) return -1;

        return max(lh,rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int ans = check(root);

        if(ans==-1){
            return false;
        }

        return true;
    }
};