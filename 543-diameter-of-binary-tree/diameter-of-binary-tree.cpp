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

    pair<int,int> diameterFast(TreeNode* root){
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        //first --> diameter second--> height
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        //diameter of left subtree
        int op1 = left.first;

        //diameter of right subtree
        int op2 = right.first;

        //height of the right left and a root node
        int op3 = left.second + right.second;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        //height wala formula;
        ans.second = max(left.second,right.second)+1;
        
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }   
};