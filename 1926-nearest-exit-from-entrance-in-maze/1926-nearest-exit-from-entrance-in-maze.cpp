class Solution {
public:
    int m, n;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m=maze.size();
        n=maze[0].size();

        queue<pair<int, int>> q;

        int ex=entrance[0];
        int ey=entrance[1];

        int ans=1;

        q.push({ex, ey});

        maze[ex][ey]='+';

        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int k=0;k<4;k++) {
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&maze[nx][ny]!='+') {
                        if(nx==0||nx==m-1||ny==0||ny==n-1) {
                            return ans;
                        } else {
                            maze[nx][ny]='+';
                            q.push({nx, ny});
                        }
                    }
                }

            }
            ans++;
        }
        return -1;
    }
};