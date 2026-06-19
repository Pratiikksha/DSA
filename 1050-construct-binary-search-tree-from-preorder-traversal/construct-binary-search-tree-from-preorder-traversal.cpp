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
    void buildTree(TreeNode* root, TreeNode* node){
        TreeNode* temp=root;
        int child=-1;
        while(temp){
            if(temp->val>node->val){
                if(temp->left){
                    temp=temp->left;
                }
                else{
                    child=0;
                    break;
                }
                child=0;
            }
            else{
                if(temp->right){
                    temp=temp->right;
                }
                 else{
                    child=1;
                    break;
                }
                child=1;
            }
        }
        if(!child) temp->left=node;
        else temp->right=node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return nullptr;
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<n;i++){
            TreeNode* x=new TreeNode(preorder[i]);
            buildTree(root,x);
        }
        return root;
    }
};