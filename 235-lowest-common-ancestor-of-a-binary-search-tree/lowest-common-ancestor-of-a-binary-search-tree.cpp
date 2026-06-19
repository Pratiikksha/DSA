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
public:
    // TreeNode* LCA(TreeNode*root,TreeNode*p,TreeNode* q){
    //     if(!root) return nullptr;
    //     if(root==p|| root==q) return root;
    //     TreeNode* left=LCA(root->left,p,q);
    //     TreeNode* right=LCA(root->right,p,q);
    //     if(left && right) return  root;
    //     return left?left:right;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};