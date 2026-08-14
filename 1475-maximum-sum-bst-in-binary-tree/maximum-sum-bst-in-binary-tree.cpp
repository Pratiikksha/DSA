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
    int ans=0;
    //{isBST,MaxVal,MinVal, sum}
    vector<int> solve(TreeNode* root){
        if(!root){
            return {1,INT_MIN, INT_MAX, 0};
        }
        auto left= solve(root->left);
        auto right= solve(root->right);

        if(left[0] && right[0] && 
        left[1]<root->val && right[2]>root->val){
            int sum =root->val+left[3]+right[3];
            ans = max(ans, sum);
            int mn=min(left[2],root->val);
            int mx=max(right[1], root->val);
            return {1,mx,mn,sum};
        }
        return {0,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};