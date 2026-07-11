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
//  dont do the mistack that you have done in this thing , in this you didn't check the function type and diden't return the statement so your code is faild , her you got to know that , but in the exams , althought you ghave written the solid logic , if you have not return the thing perfectly it will definatly going to throw error so be aware of that , make sure that you do the sufficient practice of it .

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        swap(root->left , root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};
