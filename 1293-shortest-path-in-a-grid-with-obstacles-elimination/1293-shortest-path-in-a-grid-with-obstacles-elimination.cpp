class Solution {
public:
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
    int shortestPath(vector<vector<int>>& g, int k) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<vector<int>> q;
        
        q.push({0,0,0,k});
        while(!q.empty()) {
            auto node=q.front();
            q.pop();
            int x=node[0], y=node[1], steps=node[2], k=node[3];
            
            if(x<0||x>=m||y<0||y>=n) {
                continue;
            }
            
            if(x==m-1&&y==n-1) {
                return steps;
            }
            
            if(g[x][y]==1) {
                if(k>0) k--;
                else continue;
            }
            
            if(vis[x][y]!=-1&&vis[x][y]>=k) continue;
            vis[x][y]=k;
            
            for(int i=0;i<4;i++) {
                int nx=x+dx[i];
                int ny=y+dy[i];
                q.push({nx,ny,steps+1,k});
            }
        }
        
        return -1;
    }
};