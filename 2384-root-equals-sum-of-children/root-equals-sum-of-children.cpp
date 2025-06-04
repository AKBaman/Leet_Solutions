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
    TreeNode* child(TreeNode* root){
        if(!root){return NULL;}
        if(!root->left && !root->right){
            return root;
        }
        TreeNode* left = child(root->left);
        TreeNode* right = child(root->right);
        
        if(left->val+right->val == root->val){
            return root;
        }
        else{
            return NULL;
        }
    }
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        if(child(root)){
            return true;
        }
        return false;
    }
};