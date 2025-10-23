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
    TreeNode* prev = nullptr;

    void flattentree(TreeNode* root){
        if(!root) return;
        
        flattentree(root->right);
        flattentree(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    void flatten(TreeNode* root) {
        prev = nullptr;
        flattentree(root);
    }
};