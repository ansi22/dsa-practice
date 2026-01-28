class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& v, int node) {
        v[node]=1;

        for(auto child: g[node]) {
            if((v[child]==0&&dfs(g, v, child))||v[child]==1) {
                return 1;
            }
        }

        v[node]=2;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> v(n, 0), res;

        for(int i=0;i<g.size();i++) {
            if(v[i]==2 || !dfs(g, v, i)) {
                res.push_back(i);
            }
        }

        return res;
    }
};