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
    void flatten(TreeNode* root) {
        //using morris Traversal but maintaing the link as it is 
        //remove the right connection of root


        TreeNode* curr = root;

        while(curr){
            if(!curr->left){
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;

                while(prev->right != NULL && prev->right!=curr){
                    prev = prev->right;
                }

                if(prev->right==NULL){
                    prev->right = curr->right;
                    curr->right=curr->left;
                    curr->left = NULL;
                    curr=curr->right;
                }
            }
        }
    }
};