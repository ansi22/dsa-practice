class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        priority_queue<int, vector<int>, greater<int>> nodeg;
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1);

        vector<int> ans(n);
        int ind=0;

        for(auto x: pre) {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        for(int i=0;i<n;i++) {
            if(indegree[i]==0) {
                nodeg.push(i);
            }
        }

        while(!nodeg.empty()) {
            auto node=nodeg.top();
            nodeg.pop();

            ans[ind++]=node;

            for(auto child: graph[node]) {
                indegree[child]--;
                if(indegree[child]==0) {
                    nodeg.push(child);
                }
            }
        }

        if(ind!=n) {
            return {};
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};