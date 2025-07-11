class Solution {
    void solve(vector<int>& nums,vector<vector<int>> &ans,int idx){
        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for(int i = idx;i<n;i++){
            swap(nums[i],nums[idx]);
            solve(nums,ans,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
public:
int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};