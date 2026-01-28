class Solution {
public:
    const int INF=1e9;
    int findTheCity(int n, vector<vector<int>>& g, int dis) {
        vector<vector<int>> dp(n, vector<int>(n, INF));
        int ans=0, mini=INF;

        for(auto x: g) {
            dp[x[0]][x[1]]=x[2];
            dp[x[1]][x[0]]=x[2];
        }

        for(int i=0;i<n;i++) {
            dp[i][i]=0;
        }

        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(dp[i][k]<INF&&dp[k][j]<INF) {
                        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
                    }
                }
            }
        }

        for(int i=0;i<n;i++) {
            int cnt=0;
            for(int j=0;j<n;j++) {
                if(dp[i][j]<=dis) {
                    cnt++;
                }
            }

            if(cnt<=mini) {
                ans=i;
                mini=cnt;
            }
        }

        return ans;
    }
};
