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
    int solve(TreeNode* root,int &ans){
        if(root == nullptr){
            return 0;
        }
        int leftMax = max(0,solve(root->left,ans));
        int rightMax = max(0,solve(root->right,ans));
        ans = max(ans,root->val + leftMax + rightMax);
        return (root->val + max(leftMax,rightMax));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};