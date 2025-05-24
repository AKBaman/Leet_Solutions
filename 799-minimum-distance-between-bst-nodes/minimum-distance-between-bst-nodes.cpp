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
    void inorder(TreeNode* root,vector<int>& ans){
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;

                while(prev->right != NULL && prev->right!=curr){
                    prev=prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int res = INT_MAX;

        for(int i=0;i<ans.size()-1;i++){
            if(ans[i+1]-ans[i] < res){
                res = ans[i+1]-ans[i];
            }
        }

        return res;
    }
};