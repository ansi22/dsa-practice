class Solution {
public:
    vector<vector<int>> memo;
    int mod=1e9+7;
    int len;
    int dp(int curr, int remain) {
        if(remain==0) {
            if(curr==0) {
                return 1;
            }
            return 0;
        }

        if(memo[curr][remain]!=-1) {
            return memo[curr][remain];
        }

        int ans=dp(curr, remain-1);
        if(curr>0) {
            ans=(ans+dp(curr-1, remain-1))%mod;
        }
        if(curr<len-1) {
            ans=(ans+dp(curr+1, remain-1))%mod;
        }

        memo[curr][remain] = ans;
        return ans;
    }
    int numWays(int steps, int arrLen) {
        len=arrLen;
        arrLen=min(arrLen, steps);
        memo=vector(arrLen, vector(steps + 1, -1));
        return dp(0, steps);
    }
};