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
    void Traversal(TreeNode* root,vector<vector<int>>&ans,vector<int>&arr){
        queue<TreeNode*>q;

        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                ans.push_back(arr);
                arr.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                arr.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return;

    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>>ans;
        vector<int> temp;
        Traversal(root,ans,temp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};