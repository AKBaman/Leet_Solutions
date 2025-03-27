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
    void sum (TreeNode* root,int current,int& total){
        if(!root) return;
        current = current*10 + root->val;
        if(!root->left && !root->right){
            total+=current;
            return;
        }

        sum(root->left,current,total);
        sum(root->right,current,total);
    }
    int sumNumbers(TreeNode* root) {
        int val=0;
        sum(root,0,val);
        return val;
    }
};