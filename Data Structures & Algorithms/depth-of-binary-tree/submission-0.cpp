/**
If root is null, return 0.
Otherwise:
Recursively compute leftDepth = maxDepth(root.left).
Recursively compute rightDepth = maxDepth(root.right).
Return 1 + max(leftDepth, rightDepth).

*/


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
