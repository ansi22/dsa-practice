 vector<int> factors[1000001];
    bool p=[]() {
        for(int i=2;i<1000001;i++) {
            if(factors[i].empty()) {
                for(int j=i;j<1000001;j+=i) {
                    factors[j].push_back(i);
                }
            }
        }
        return true;
    }();
class Solution {
   
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, vector<int>> edges;

        for(int i=0;i<n;i++) {
            int x=nums[i];
            if(factors[x].size()==1) {
                edges[x].push_back(i);
            }
        }
        int res=0;
        vector<bool> vis(n, false);
        vis[n-1]=true;
        vector<int> q={n-1};
        while(1) {
            vector<int> q2;
            for(auto i: q) {
                if(i==0) return res;
                if(i>0 and !vis[i-1]) {
                    vis[i-1]=1;
                    q2.push_back(i-1);
                }
                if(i<n-1 and !vis[i+1]) {
                    vis[i+1]=1;
                    q2.push_back(i+1);
                }
                for(int p: factors[nums[i]]) {
                    if(edges.count(p)) {
                        for(int j: edges[p]) {
                            if(!vis[j]) {
                                vis[j]=1;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q=move(q2);
            res++;
        }
    }
};