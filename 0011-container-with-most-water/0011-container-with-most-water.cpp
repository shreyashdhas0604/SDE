class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n-1;
        int ans = 0;
        while(l < r){
            int length = (r-l);
            int height = min(nums[l],nums[r]);
            ans = max(ans,(length*height));

            if(nums[l] < nums[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
    }
};