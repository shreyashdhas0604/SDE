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
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // if((root->left && !root->right) || (!root->left && root->right)){
        //     return false;
        // }

        int leftht = height(root->left);
        int rightht = height(root->right);
        if(abs(leftht-rightht) > 1) return false;
        if(isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};