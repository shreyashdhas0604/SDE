class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n),right(n);
        left[0] = 0;
        right[n-1] = 0;
        int leftmax = nums[0],rightmax = nums[n-1];
        for(int i = 1;i<n;i++){
            leftmax = max(leftmax,nums[i]);
            left[i] = leftmax;
        }

        for(int i = n-2;i>=0;i--){
            rightmax = max(rightmax, nums[i]);
            right[i] = rightmax;
        }
        int maxans = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int l = min(left[i],right[i]);
            if(nums[i] < l) ans = ans + (l - nums[i]);
        }

        return ans;
    }
};