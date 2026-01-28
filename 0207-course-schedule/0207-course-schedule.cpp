class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        if(pre.empty()) {
            return 1;
        }

        priority_queue<int, vector<int>, greater<int>> nodeg;
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1);
        int check=0;
        
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
            check++;

            for(auto child: graph[node]) {
                indegree[child]--;
                if(indegree[child]==0) {
                    nodeg.push(child);
                }
            }

        }

        return check==n;
    }
};

/*

Uses in-degree counting.
Repeatedly removes nodes with zero in-degree, adds them to the result, and reduces in-degree of their neighbors.
If not all nodes are processed, a cycle exists.
Time complexity: $ O(V + E) $

*/ 