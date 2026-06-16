/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findDepth(TreeNode* root){
        if(!root) return 0;
        int rightDepth=1+findDepth(root->right);
        int leftDepth=1+findDepth(root->left);
        return max(rightDepth,leftDepth);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftDepth=findDepth(root->left);
        int rightDepth=findDepth(root->right);
        if(abs(leftDepth-rightDepth)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);

    }
};