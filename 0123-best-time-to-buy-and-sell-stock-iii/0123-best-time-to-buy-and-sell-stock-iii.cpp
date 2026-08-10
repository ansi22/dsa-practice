class Solution {
public:
    int getMaxProfit(vector<vector<int>>& dp, vector<int>& prices, int cur, int trans) {
        if(cur==prices.size() or trans==0) {
            return 0;
        }

        if(dp[cur][trans]!=-1) {
            return dp[cur][trans];
        }

        int op1=getMaxProfit(dp, prices, cur+1, trans);
        int op2;

        if(trans%2==0) {
            op2=getMaxProfit(dp, prices, cur+1, trans-1)-prices[cur];
        } else {
            op2=getMaxProfit(dp, prices, cur+1, trans-1)+prices[cur];
        }

        return dp[cur][trans]=max(op1, op2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, -1));
        return getMaxProfit(dp, prices, 0, 4);
    }
};

