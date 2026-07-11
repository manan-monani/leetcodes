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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; 
        // this means that the both should reach to null and return 0 and we convert them into the 1 && 1 so that we can return true , this is the base case for the recursive function .
        // Remember to firstly write the Base case in the recursive function.

        if(p && q && p->val == q->val){
            return isSameTree(p->left , q->left) && isSameTree(p->right,q->right);
        }
        else return false;


    }
};
