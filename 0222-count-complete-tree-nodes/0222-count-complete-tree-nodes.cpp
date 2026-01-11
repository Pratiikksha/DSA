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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int lh = findHeightLeft(root->left);
        int rh = findHeightRight(root->right);
        if (lh == rh)
            return (1 <<(lh+1)) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int findHeightLeft(TreeNode* root) {
        int f=0;
        while (root) {
            f++;
            root = root->left;
        }
        return f;
    }
    int findHeightRight(TreeNode* root) {
        int f=0;
        while (root) {
            f++;
            root = root->right;
        }
        return f;
    }
};