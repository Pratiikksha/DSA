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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p)
            return p;
        if (root == q)
            return q;
        if ((p->val < root->val && root->val < q->val) ||
            (p->val > root->val && root->val > q->val)) {
            return root;
        } else {
            if (p->val < root->val) {
                return LCA(root->left, p, q);
            } else
                return LCA(root->right, p, q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};