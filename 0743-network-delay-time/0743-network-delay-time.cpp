#define INF 1e9+10
const int N=1e5+10;
class Solution {
public:
    int dijkstra(int source, int n, vector<pair<int, int>> g[N]) {
        vector<int> vis(N, 0);
        vector<int> dist(N, INF);
        dist[source]=0;
        multiset<pair<int, int>> st;
        st.insert({0, source});

        while(!st.empty()) {
            auto p=*st.begin();
            int x=p.second;
            st.erase(st.begin());
            if(vis[x]) continue;

            vis[x]=1;

            for(auto child: g[x]) {
                int y=child.first;
                int wt=child.second;
                if(dist[x]+wt<dist[y]) {
                    dist[y]=dist[x]+wt;
                    st.insert({dist[y], y});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(dist[i]==INF) return -1;
            ans=max(ans, dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> g[N];
        for(auto child: times) {
            g[child[0]].push_back({child[1],child[2]});
        }
        return dijkstra(k, n, g);
    }
};