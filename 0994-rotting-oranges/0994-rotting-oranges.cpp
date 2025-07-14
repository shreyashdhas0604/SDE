class Solution {
public:
    void solve(vector<vector<int>>& grid,int n,int m,int &minutes){
        queue<pair<pair<int,int>,int>> q;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},minutes});
                }
            }
        }

        int ans = 0;
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int r = ele.first.first;
            int c = ele.first.second;
            int mint = ele.second;
            vis[r][c] = true; 

            for(int i = 0;i<4;i++){
                int newi = r + dx[i],newj = c + dy[i];
                if(newi < n && newi >=0 && newj >= 0 && newj < m && !vis[newi][newj] && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        q.push({{newi,newj},mint+1});
                        minutes = mint +1;
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int minutes = 0;
        solve(grid,n,m,minutes);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minutes;
    }
};