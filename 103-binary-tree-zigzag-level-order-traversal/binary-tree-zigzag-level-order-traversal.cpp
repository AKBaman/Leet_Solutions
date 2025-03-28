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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; //Conventional traversal
        while(!q.empty()){
            int size = q.size();
            vector<int> tempArr(size);
            //level Process: ek level ke saare elements daal diye
            for(int i=0;i<size;i++){
                //accesing the front node
                TreeNode* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size-i-1;

                tempArr[index] = frontNode->val;

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(tempArr);
        }

        return ans;
    }
};