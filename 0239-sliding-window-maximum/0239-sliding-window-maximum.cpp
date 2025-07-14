class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int j = 0,n = nums.size();
        for(int i = 0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i = k;i<n;i++){
            int num = nums[i];
            pq.push({nums[i],i});
            int invalidIndex = i - k; 
            
            while(pq.top().second <= invalidIndex){
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};