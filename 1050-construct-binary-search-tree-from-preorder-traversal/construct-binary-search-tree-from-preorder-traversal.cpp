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
    int idx = 0;

    TreeNode* build(vector<int>& pre, int bound) {
        if (idx == pre.size() || pre[idx] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(pre[idx++]);

        root->left = build(pre, root->val);
        root->right = build(pre, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};