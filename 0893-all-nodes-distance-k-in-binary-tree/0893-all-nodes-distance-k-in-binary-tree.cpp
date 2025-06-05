/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void findParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;

        //using BFS for parent marking
        findParents(root,parent);

        unordered_map<TreeNode*,bool> visited;
        int level = 0;
        //2nd time using BFS for level wise traversal

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        while(!q.empty()){
            int size = q.size();
            if(level++ == k) break;
            //using the for loop for exploring the node at the certain level completely
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }

                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    visited[parent[temp]] =  true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};