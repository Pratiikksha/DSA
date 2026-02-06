/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "#,";
        string s=to_string(root->val)+',';
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index=0;
        return buildTree(data,index);
    }
    TreeNode* buildTree(string data, int& index){
      if(data[index]=='#') {
        index+=2;
        return NULL;
      }
      int sign=1;
      if(data[index]=='-'){
        sign=-1;
        index++;
      }
      string n="";
      while(data[index]!=','){
        n+=data[index];
        index++;
      }
      index++;
      int k=stoi(n);
      TreeNode* root=new TreeNode(k*sign);
      root->left=buildTree(data,index);
      root->right=buildTree(data,index);
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));