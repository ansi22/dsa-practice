class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& col, int node) {
        if(col[node]==-1) {
            col[node]=1;
        }

        for(auto child: graph[node]) {
            if(col[child]==col[node]) {
                return false;
            } else if(col[child]==-1) {
                col[child]=1^col[node];
                if(!dfs(graph, col, child)) {
                    return false;
                }
            }
        }

        return true;
    }
   
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n, -1);

        for(int i=0;i<n;i++) {
            if(col[i]==-1) {
                if(!dfs(graph, col, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};