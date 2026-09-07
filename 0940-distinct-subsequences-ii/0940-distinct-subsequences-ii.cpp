class Solution {
public:
    int distinctSubseqII(string s) {
        const int n=s.length();
        const int mod = 1e9+7;
        vector<int> dp(n+1);
        dp[0]=1;
        vector<int> last(26, -1);

        for(int i=0;i<n;i++) {
            int x=s[i]-'a';
            dp[i+1]=dp[i]*2%mod;
            if(last[x]>=0) {
                dp[i+1]-=dp[last[x]];
            }
            dp[i+1]%=mod;
            last[x]=i;
        }
        dp[n]--;
        if(dp[n]<0) dp[n]+=mod;
        return dp[n];

    }
};

/*
['a','b','a','b']
[0, 1, 2, 3]

dp[0]=2: "", "a"
dp[1]: "", "a", "b", "ab"
dp[2]: "", "a", "b", "aa", "ab", "ba", "aba"
dp[3]: "", "a", "b", "aa", "ab", "ba", "aba", "aab", "aab", "abb", "bab", "abab"

*/ 