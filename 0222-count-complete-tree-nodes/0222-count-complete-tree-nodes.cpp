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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left  = HeightLeft(root);
        int right = HeightRight(root);

        //left and right equal means tree is complete so directly returning value
        if(left  == right) return (1<<left) - 1;

        //otherwise counting the nodes in left and right ans root
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int HeightLeft(TreeNode* node){
        if(!node) return 0;
        int count=0;
        while(node){
            count++;
            node = node->left;
        }
        return count;
    }

    int HeightRight(TreeNode* node){
        if(!node) return 0;
        int count=0;
        while(node){
            count++;
            node = node->right;
        }
        return count;
    }
};