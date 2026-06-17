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
    bool pathfind(TreeNode* a, TreeNode* root, vector<TreeNode*>& path) {
        if (!root)
            return false;
        path.push_back(root);
        if (root == a) {
            return true;
        } else {
            if (pathfind(a, root->left, path) || pathfind(a, root->right, path))
                return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        pathfind(p, root, path1);
        pathfind(q, root, path2);
        int n = path1.size();
        int m = path2.size();
        TreeNode* ans=root;
        for (int j = 0; j < min(n, m); j++) {
            if (path1[j] == path2[j]) {
                ans=path1[j];
            }
            else return ans;
        }
        return ans;
    }
};