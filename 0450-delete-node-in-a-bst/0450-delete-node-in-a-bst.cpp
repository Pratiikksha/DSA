/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
     TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        // If root itself needs to be deleted
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;

        // Search for the node
        while (root != NULL) {
            if (key < root->val) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            }
            else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

private:
    TreeNode* helper(TreeNode* root) {
        // Case 1: no left child
        if (root->left == NULL) {
            return root->right;
        }
        // Case 2: no right child
        else if (root->right == NULL) {
            return root->left;
        }

        // Case 3: two children
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};