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
    //pointer for the previous element
    TreeNode* pre;

    //prev of the first violation
    TreeNode* first;

    //root of the first violation
    TreeNode* middle;

    //root of the last violation
    TreeNode* last;

    void build(TreeNode* root){
        if(!root) return;
        build(root->left);
        if(pre && (root->val < pre->val)){
            //check whether it the first violation or not
            //if first violation mark 
            //"first"  and "middle"
            if(!first){
                first = pre;
                middle = root;
            }
            else{
                //check for the last violation
                //mark the last violatin 
                last = root;
            }
        }
        pre = root;
        build(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        pre = NULL;
        build(root);
        //check whether "first" and "last" exists that is nodes which are
        //not adjacent are swapped
        if(first && last){
            swap(first->val ,last->val);
        }
        //nodes whcih are adjacent are swapped
        else if(first && middle){
            swap(first->val ,middle->val);
        }

    }
};