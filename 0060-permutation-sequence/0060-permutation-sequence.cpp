class Solution {
public:
    vector<int> np(vector<int> nums){
        int n = nums.size();
        int i = n-2,j = n-1;

        while(i >=0 && nums[i] >= nums[i+1]){
            i--;
        }

        if(i >= 0){
            while(i<=j && nums[j] <= nums[i] ){
                j--;
            }
            swap(nums[i],nums[j]);
        }

        reverse(nums.begin()+i+1,nums.end());
        return nums;
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i =1;i<=n;i++) nums.push_back(i);

        for(int i = 1;i<k;i++){
            nums = np(nums);
        }

        string ans = "";
        for(int num : nums) ans += to_string(num);

        return ans;
     }
};