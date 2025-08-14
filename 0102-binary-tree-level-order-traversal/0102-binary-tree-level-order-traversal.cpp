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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>> ();
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<pair<int,int>> ans;
        int maxlevel = 0;
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            if(ele.first != nullptr){
                maxlevel = max(maxlevel,ele.second);
                ans.push_back({ele.second,ele.first->val});
            }

            if(ele.first && ele.first->left){
                q.push({ele.first->left,ele.second + 1});
            }
            if(ele.first && ele.first->right){
                q.push({ele.first->right,ele.second + 1});
            } 
        }

        vector<vector<int>> res(maxlevel+1);
        for(auto ele : ans){
            res[ele.first].push_back(ele.second);
        }
        return res;

    }
};