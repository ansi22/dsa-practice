class Solution {
public:
    vector<vector<int>> dist;
    vector<vector<int>> vis;
    int m, n, ans=0;
    int dx[8]={-1,1,0,0,-1,1,-1,1};
    int dy[8]={0,0,-1,1,-1,1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        n=g.size();
        m=g[0].size();
        if(g[0][0]!=0||g[n-1][m-1]!=0) {
            return -1;
        }
        dist.resize(n, vector<int>(m, INT_MAX));
        vis.resize(n, vector<int>(m, 0));
        dist[0][0]=1;
        queue<pair<int, int>> q;
        q.push({0,0});


        while(!q.empty()) {
            auto node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;
            vis[x][y]=1;
            for(int i=0;i<8;i++) {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]==0) {
                    if(!vis[nx][ny]&&dist[nx][ny]>dist[x][y]+1) {
                        dist[nx][ny]=dist[x][y]+1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        if(dist[n-1][m-1]==INT_MAX) return -1;
        return dist[n-1][m-1];

    }
};