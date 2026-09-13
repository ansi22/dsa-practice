class Solution {
public:
    const int dx[4]={-1, 1, 0, 0};
    const int dy[4]={0, 0, -1, 1};
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]=='0') {
            return;
        }
        grid[x][y]='0';
    
        for(int k=0;k<4;k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            dfs(grid, nx, ny, m, n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    ans+=1;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return ans;

    }
};