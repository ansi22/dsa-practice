class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedintervals;
        sort(intervals.begin(), intervals.end());
        auto cur=intervals[0];
        for(auto x: intervals) {
            if(x[0]<=cur[1]) {
                cur[1]=max(x[1], cur[1]);
            } else {
                mergedintervals.push_back(cur);
                cur=x;
            }
        }

        mergedintervals.push_back(cur);
        return mergedintervals;
    }
};

