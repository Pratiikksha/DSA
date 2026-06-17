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
    using T=tuple<int,int,int>;
    void addNodes(int x,int y,TreeNode* root,priority_queue<T,vector<T>,greater<T>>& pq){
        if(!root) return;
        pq.push({x,y,root->val});
        if(root->left){
            addNodes(x-1,y+1,root->left,pq);
        }
        if(root->right){
            addNodes(x+1,y+1,root->right,pq);
        }
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<T,vector<T>,greater<T>> pq;
        addNodes(0,0,root,pq);
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> temp;
            auto [x,y,val]=pq.top();
            temp.push_back(val);
            pq.pop();
            while(!pq.empty()){
                auto [x1,y1,val1]=pq.top();
                if(x1!=x){
                    break;
                }
                else{
                    pq.pop();
                    temp.push_back(val1);
                }
            }
            if(!temp.empty()){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};