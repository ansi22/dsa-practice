class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0, n=cardPoints.size();
        for(int i=0;i<k;i++) {
            ans+=cardPoints[i];
        }
        int cur=ans;
        for(int i=k-1;i>=0;i--) {
            cur-=cardPoints[i];
            cur+=cardPoints[n-k+i];
            ans=max(ans, cur);
        }
        return ans;
    }
};