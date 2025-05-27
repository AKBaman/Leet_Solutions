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
    void find(TreeNode* root,int val,TreeNode* &res){
        if(!root || res!=nullptr) return;
        if(root->val == val){
            res = root;
            return;
        }
        find(root->left,val,res);
        find(root->right,val,res);
        return;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = NULL;
        find(root,val,res);
        return res;
        
    }
};