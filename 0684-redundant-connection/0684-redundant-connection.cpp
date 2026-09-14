class unionFind {
private:
    int n;
    vector<int> parent, size;
public:
    unionFind(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0;i<n;i++) {
            parent[i]=i;
        } 
    }

    int findParent(int i) {
        if(parent[i]==i) {
            return i;
        }

        return parent[i]=findParent(parent[i]);
    }

    bool unite(int u, int v) {
        u=findParent(u);
        v=findParent(v);

        if(u==v) {
            return false;
        }

        if(size[u]<size[v]) {
            parent[u]=v;
            size[v]+=size[u];
        } else {
            parent[v]=u;
            size[u]+=size[v];
        }
        return true;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unionFind graph(n+1);

        for(auto x: edges) {
            if(!graph.unite(x[0], x[1])) {
                return x;
            }
        }

        return {};
    }
};