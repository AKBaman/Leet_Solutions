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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //using a verticle order traversal 

        //row will be the vector size

        //taking a queue for the verticle order traversal

        queue<pair<TreeNode*,pair<int,int>>> q;

        //map for the verticle rows map<row,map<level,node->val>>;
        map<int,map<int,multiset<int>>> map;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto p = q.front();
            TreeNode* temp = p.first;
            int x = p.second.first ,y=p.second.second;

            q.pop();

            // map.insert({x,{y,temp->val}});
            map[x][y].insert(temp->val);

            if(temp->left){
                q.push({temp->left , {x-1,y+1}});
            }
            if(temp->right){
                q.push({temp->right, { x+1,y+1}});
            }

        }

        vector<vector<int>> ans;

        for(auto it : map){
            vector<int> values;
            for(auto num : it.second){
                values.insert(values.end(),num.second.begin(),num.second.end());
            }
            ans.push_back(values);
        }

        return ans;
    }
};