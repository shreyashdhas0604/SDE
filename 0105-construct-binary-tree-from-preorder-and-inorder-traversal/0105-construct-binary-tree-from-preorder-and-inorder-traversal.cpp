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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> myMap;
        int n = inorder.size(), m = preorder.size();
        for(int i = 0;i<n;i++){
            myMap[inorder[i]] = i;
        }

        return buildTree(preorder,0,m-1,inorder,0,n-1,myMap);
    }

    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &myMap){
        if(preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = myMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder,preStart + 1,preStart + numsLeft ,inorder,inStart,inRoot-1,myMap);
        root->right = buildTree(preorder,preStart + numsLeft + 1,preEnd,inorder,inRoot + 1,inEnd,myMap);

        return root;
        
    }
};