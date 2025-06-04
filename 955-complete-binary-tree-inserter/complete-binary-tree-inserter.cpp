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
class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> q;

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> tempQ;
        tempQ.push(root);

        while (!tempQ.empty()) {
            TreeNode* node = tempQ.front();
            tempQ.pop();

            // If node is not full, add to q for future insert
            if (!(node->left && node->right)) {
                q.push(node);
            }

            if (node->left) tempQ.push(node->left);
            if (node->right) tempQ.push(node->right);
        }
    }

    int insert(int val) {
        TreeNode* node = q.front(); // node to insert into
        TreeNode* newNode = new TreeNode(val);

        if (!node->left) {
            node->left = newNode;
        } else {
            node->right = newNode;
            q.pop(); // remove node from queue as it's now full
        }

        q.push(newNode); // add new node to queue for future insertions
        return node->val;
    }

    TreeNode* get_root() {
        return root;
    }
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */