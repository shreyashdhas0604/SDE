class Solution {

    bool valid(vector<string>& ans, int r, int c) {

        // for (int i = r; i >= 0; i--) {
        //     if (ans[i][c] == 'Q') {
        //         return false;
        //     }
        // }
        for (int i = c; i >= 0; i--) {
            if (ans[r][i] == 'Q') {
                return false;
            }
        }

        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            if (ans[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = r, j = c; i >=0 && j >= 0; i--, j--) {

            if (ans[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board,vector<vector<string>> &ans, int r, int c) {
        if(c == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0;i<n;i++){
            if(valid(board,i,c)){
                board[i][c] = 'Q';
                solve(board,ans,r,c+1);
                board[i][c] = '.';
            }
        }
        
    }

    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
    vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(board,ans, 0, 0);
        return ans;
    }
};

