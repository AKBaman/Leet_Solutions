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
    pair<bool,int> FastCheck(TreeNode* root){
        if(!root){
            pair<bool,int> p = {true, 0};
            return p;
        }
        pair<bool,int> left = FastCheck(root->left);
        pair<bool,int> right= FastCheck(root->right);

        bool lefts = left.first;
        bool rights = right.first;
        bool diff = abs(left.second - right.second) <=1;

        pair<bool,int> ans ;
        ans.first = (lefts && rights && diff);
        ans.second =  max(left.second,right.second) + 1;
        return ans;

    }
    bool isBalanced(TreeNode* root) {
        return FastCheck(root).first;
    }
};