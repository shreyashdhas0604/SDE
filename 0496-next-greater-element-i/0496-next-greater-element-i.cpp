class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        stack<int> st;
        unordered_map<int,int>mp;
        for(int i = 0;i<n2;i++){
            while(!st.empty() && st.top() < nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
                
        }
        vector<int> ans;
        for(int num : nums1){
            if(mp.find(num) != mp.end()){
                ans.push_back(mp[num]);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};