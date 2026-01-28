class Solution {
public:
    const int dx[4]={0, 0, -1, 1};
    const int dy[4]={-1, 1, 0, 0};
    void dfs(int x, int y, int mid, vector<vector<int>>& h, int m, int n, vector<vector<int>>& vis) {
        if(vis[x][y]) return;
        vis[x][y]=1;

        for(int k=0;k<4;k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx<0||ny<0||nx>=m||ny>=n) {
                continue;
            }

            if(abs(h[x][y]-h[nx][ny])<=mid) {
                dfs(nx, ny, mid, h, m, n, vis);
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int m=h.size();
        int n=h[0].size();
        int maxi=0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                maxi=max(maxi, h[i][j]);
            }
        }

        int st=0, en=maxi, mid, ans=-1;

        while(st<=en) {
            mid=st+(en-st)/2;
            vector<vector<int>> vis(m, vector<int>(n, 0));

            dfs(0, 0, mid, h, m, n, vis);

            if(vis[m-1][n-1]) {
                ans=mid;
                en=mid-1;
            } else st=mid+1;
        }

        return ans;

    }
};