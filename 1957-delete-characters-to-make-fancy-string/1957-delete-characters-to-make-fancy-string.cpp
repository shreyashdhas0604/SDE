class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        for(int i=0;i<s.size();i++){
            int n=result.size();
            if(n>=2 && result[n-1] == s[i] && result[n-2] == s[i]){
                continue;
            }
            result += s[i];
        }
        return result;
    }
};