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
    int check(TreeNode* root,vector<int>& ans){
        if(!root) return 0;

        int lh = check(root->left,ans);
        int rh = check(root->right,ans);

        if(lh==rh && lh!=-1 && rh!=-1){
            ans.push_back(pow(2,lh+1)-1);
        }
        else{
            return -1;
        }
        
        return max(lh,rh)+1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> ans;
        check(root,ans);
        if(ans.size() < k){
            return -1;
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans[k-1];
    }
};