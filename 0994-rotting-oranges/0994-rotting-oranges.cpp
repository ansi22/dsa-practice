class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), fresh=0, ans=-1;
        queue<pair<int, int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                } else if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }

        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto node=q.front();
                auto x=node.first;
                auto y=node.second;
                q.pop();

                for(int k=0;k<4;k++) {
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==1) {
                        grid[nx][ny]=2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            ans++;
        }

        if(fresh>0) return -1;
        if(ans==-1) return 0;
        return ans;
    }
};