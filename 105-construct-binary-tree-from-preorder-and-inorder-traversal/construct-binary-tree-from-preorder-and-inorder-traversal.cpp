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
    unordered_map<int,int>mp;
    TreeNode* build(vector<int>& preorder,int preL, int preR, vector<int>& inorder, int inL, int inR){
        if(preL>preR || inL>inR){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[preL]);
        int k=mp[preorder[preL]];
        root->left=build(preorder,preL+1,preL+k-inL,inorder,inL,k-1);
        root->right=build(preorder,preL+k-inL+1,preR,inorder,k+1,inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder, 0, preorder.size()-1,inorder,0,inorder.size()-1);
    }
};