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
    int ans=-1;
    bool Inorder(TreeNode* root,int k,int& curr){
        if(!root) return false;
        Inorder(root->left,k,curr);
        curr++;
        if(curr==k) {
            ans=root->val;
            return true;
        } 
        Inorder(root->right,k,curr);
        return true;
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        Inorder(root,k,c);
        return ans;
    }
};