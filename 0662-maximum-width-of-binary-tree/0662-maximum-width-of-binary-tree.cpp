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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int maxi=1;
        while(!q.empty()){
            int size=q.size();
            long long minn=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                long long p=q.front().second-minn;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)
                 first=p;
                if(i==size-1)
                 last=p;
                if(node->left){
                    q.push({node->left,p*2+1});
                } 
                if(node->right){
                    q.push({node->right,p*2+2});
                }
            }
            maxi=max(maxi,(int)(last-first+1));
        }
        return maxi;
    }
};