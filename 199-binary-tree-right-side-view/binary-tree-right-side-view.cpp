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
    vector<int> rightSideView(TreeNode* root) {
         if(!root) return {};
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<int>ans;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [node,x]=q.front();
                q.pop();
                if(mp.find(x)==mp.end()){
                    mp[x]=node->val;
                }
                if(node->right){
                    q.push({node->right,x+1});
                }
                if(node->left){
                    q.push({node->left,x+1});
                }
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};