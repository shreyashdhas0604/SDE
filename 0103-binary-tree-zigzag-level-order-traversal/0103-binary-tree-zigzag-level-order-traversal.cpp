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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            vector<int> level;
            int sz = q.size();
            bool flag = false;
            for(int i = 0;i<sz;i++){
                auto ele = q.front();q.pop();
                if(ele.first->left) q.push({ele.first->left,ele.second+1});
                if(ele.first->right) q.push({ele.first->right,ele.second+1});
                level.push_back(ele.first->val);
                if(ele.second % 2 != 0) flag = true;
            }
            if(flag){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};