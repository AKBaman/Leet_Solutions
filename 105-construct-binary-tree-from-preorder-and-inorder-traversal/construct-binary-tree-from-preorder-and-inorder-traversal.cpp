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
    int Find(vector<int>in,int start,int end,int target){
        for(int i=start;i<=end;i++){
            if(in[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* Tree(vector<int>pre,vector<int>in,int inStart,int inEnd,int index){
        if(inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode (pre[index]);
        int pos  = Find(in,inStart,inEnd,pre[index]);

        root->left = Tree(pre,in,inStart,pos-1,index+1);
        root->right = Tree(pre,in,pos+1,inEnd,index + (pos-inStart) + 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0,end = preorder.size()-1,index=0;
        return Tree(preorder,inorder,start,end,index);
    }
};