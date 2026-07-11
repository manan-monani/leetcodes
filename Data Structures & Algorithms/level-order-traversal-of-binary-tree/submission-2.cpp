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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int size = q.size();

            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (!level.empty()) {
                res.push_back(level);
            }
        }
        return res;
    }
};
/**


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; // Return an empty list if tree is empty
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root); // Start with the root node
        
        while (!q.empty()) {
            int level_size = q.size(); // Count nodes at the current level
            vector<int> current_level; // Stores values for this level
            
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                current_level.push_back(node->val); // Add node value to current level
                
                // Add children to the queue for the NEXT level
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(current_level); // Push the completed level into result
        }
        
        return result;
    }
};


*/
