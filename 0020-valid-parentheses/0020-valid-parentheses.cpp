class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else{
                if(!st.empty()){
                    char ch = st.top();
                    if((ch == '(' && c != ')') || (ch == '[' && c != ']') || (ch == '{' && c != '}')){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};