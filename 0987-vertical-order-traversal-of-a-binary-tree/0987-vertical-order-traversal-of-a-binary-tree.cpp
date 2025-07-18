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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> todo; // node,{vertical,level}
        map<int,map<int,multiset<int>>> nodes; // vertical -> {level -> { nodes }}
        todo.push({root,{0,0}});

        while(!todo.empty()){
            auto ele = todo.front();
            todo.pop();

            int vert = ele.second.first;
            int level = ele.second.second;
            TreeNode* node = ele.first;

            nodes[vert][level].insert({node->val});

            if(node->left){
                todo.push({node->left,{vert-1,level+1}});
            }
            if(node->right){
                todo.push({node->right,{vert+1,level+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto ele : nodes){
            vector<int> temp;
            for(auto ele1 : ele.second){
                temp.insert(temp.end(),ele1.second.begin(),ele1.second.end());
            }
            ans.push_back(temp);
        }

        return ans;

    }
};