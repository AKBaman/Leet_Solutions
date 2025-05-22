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
    TreeNode* deleteNode(TreeNode* root, int target) {
        //base condition 
        if(!root) return NULL;

        if(target < root->val){
            root->left = deleteNode(root->left,target);
            return root;
        }
        else if(target > root->val){
            root->right = deleteNode(root->right,target);
            return root;
        }
        else{
            //leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            //1 child exists
            else if(!root->right){
                //left child exists
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left){
                //right child exists
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else{

                //find the greatest element from left
                TreeNode* parent = root;
                TreeNode* child = root->left;

                while(child->right){
                    parent = child;
                    child = child->right;
                }

                if(parent == root){
                    child->right= root->right;
                    delete root;
                    return child;
                }
                else{
                    parent->right=child->left;
                    child->left = root->left;
                    child->right = root->right;

                    delete root;
                    return child;
                }


            }
        }



    }
};