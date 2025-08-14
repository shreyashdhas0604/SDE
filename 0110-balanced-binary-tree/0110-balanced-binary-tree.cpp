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

    // brute solution

//     int height(TreeNode* root){
//         if(!root) return 0;
//         return max(height(root->left),height(root->right)) + 1;
//     }
public:
//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;

//         int leftht = height(root->left);
//         int rightht = height(root->right);
//         if(abs(leftht-rightht) > 1) return false;
//         if(isBalanced(root->left) && isBalanced(root->right)) return true;
//         return false;
//     }

    //optimal
    int height(TreeNode* root){
        if(!root) return 0;
        int leftht  = height(root->left);
        if(leftht == -1) return -1;
        int rightht = height(root->right);
        if(rightht == -1) return -1;
        if(abs(leftht-rightht) > 1) return -1;
        return max(height(root->left),height(root->right)) + 1;
    }


     bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};