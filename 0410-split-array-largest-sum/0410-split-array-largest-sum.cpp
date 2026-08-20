class Solution {
public:

    int memo[1001][51];
    int getMinimumLargestSplitSum(vector<int>& prefixSum, int cur, int subCnt) {
        int n=prefixSum.size()-1;
        if(memo[cur][subCnt]!=-1) {
            return memo[cur][subCnt];
        }
        if(subCnt==1) {
            return memo[cur][subCnt]=prefixSum[n]-prefixSum[cur];
        }
        int minimumLargestSplitSum = INT_MAX;
        for(int i=cur;i<=n-subCnt;i++) {
            int firstSplitSum=prefixSum[i+1]-prefixSum[cur];
            int largestSplitSum=max(firstSplitSum, getMinimumLargestSplitSum(prefixSum, i+1, subCnt-1));
            minimumLargestSplitSum=min(minimumLargestSplitSum, largestSplitSum);
            if(firstSplitSum>=minimumLargestSplitSum) {
                break;
            }
        }
        return memo[cur][subCnt]=minimumLargestSplitSum;
    }
    int splitArray(vector<int>& nums, int k) {
        memset(memo, -1, sizeof(memo));

        int n=nums.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=0;i<n;i++) {
            prefixSum[i+1]=prefixSum[i]+nums[i];
        }

        return getMinimumLargestSplitSum(prefixSum, 0, k);
    }
};
/*
options: i. to take in current array
         ii. to start a new array

*/ 