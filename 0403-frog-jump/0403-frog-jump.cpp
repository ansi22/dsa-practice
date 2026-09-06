class Solution {
public:
    unordered_map<int, int> mp;
    int dp[2001][2001]; //states= curind, prevjump
    int solve(vector<int>& stones, int n, int ind, int prev) {
        if(ind==n-1) return 1;

        if(dp[ind][prev]!=-1) {
            return dp[ind][prev];
        }
        int ans=0;
        for(int k=prev-1;k<=prev+1;k++) {
            if(k>0&&mp.find(stones[ind]+k)!=mp.end()) {
                ans=ans or solve(stones, n, mp[stones[ind]+k], k);
            }
        }

        return dp[ind][prev]=ans;

    }
    bool canCross(vector<int>& stones) {
        for(int i=0;i<stones.size();i++) {
            mp[stones[i]]=i;
        }

        memset(dp, -1, sizeof(dp));
        return solve(stones, stones.size(), 0, 0);
    }
};