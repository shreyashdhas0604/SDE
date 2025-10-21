class Solution {
private:
    void computeLPS(string s, vector<int>&lps){
        int len = 0;
        int i = 1;
        int n = s.length();

        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int>lps(n,0);
        computeLPS(s,lps);
        int maxlen = lps[n-1];
        string ans = s.substr(0,maxlen);
        return ans;
    }
};