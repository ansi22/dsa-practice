class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int buy=p[0], sell=INT_MIN;

        for(int i=0;i<p.size();i++) {
            buy=min(buy, p[i]);
            sell=max(sell, p[i]-buy);
        }

        return sell;
    }
};
