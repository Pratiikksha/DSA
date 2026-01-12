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
    unordered_map<int,int> mp;
     TreeNode* solve(vector<int>& postorder,
                    int inStart, int inEnd,
                    int postStart, int postEnd) {

        if (inStart > inEnd || postStart > postEnd)
            return NULL;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = mp[rootVal];
        int leftSize = inRoot - inStart;

        root->left = solve(postorder,
                           inStart, inRoot - 1,
                           postStart, postStart + leftSize - 1);

        root->right = solve(postorder,
                            inRoot + 1, inEnd,
                            postStart + leftSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return NULL;

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return solve(postorder, 0, n - 1, 0, n - 1);
    }
};