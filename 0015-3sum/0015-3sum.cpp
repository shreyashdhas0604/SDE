class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        int l = 0,r = n-1;
        for(int i = 0;i<n;i++){
            int num1 = nums[i];
            int l = i+1;
            int r = n-1;

            while(l <r){
                int sum = num1 + nums[l] + nums[r];
                if(sum == 0){
                    res.insert({num1,nums[l],nums[r]});
                    l++;r--;
                }
                else if(sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};