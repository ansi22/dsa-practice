class Solution {
public:
    struct IntervalData {
        int start, end, weight, originalIndex;
        // Sorting by end time ascending
        bool operator<(const IntervalData& other) const {
            return end < other.end;
        }
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<IntervalData> sortedIntervals;

        for (int i = 0; i < n; i++) {
            sortedIntervals.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(sortedIntervals.begin(), sortedIntervals.end());

        // dp[i][j] stores {max_weight, vector_of_indices} using first i intervals with at most j intervals picked
        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0LL, {}}));

        for (int i = 0; i < n; i++) { // Fixed: i < n instead of i <= n
            // 1. Carry forward previous best solutions if we skip interval i
            for (int j = 1; j <= 4; j++) {
                dp[i + 1][j] = dp[i][j];
            }

            int start = sortedIntervals[i].start;
            int weight = sortedIntervals[i].weight;
            int originalIndex = sortedIntervals[i].originalIndex;

            // 2. Find upper bound of non-overlapping interval (end < start)
            IntervalData target = {0, start, 0, 0};
            int k = lower_bound(sortedIntervals.begin(), sortedIntervals.begin() + i, target) - sortedIntervals.begin();

            // 3. Try picking the current interval
            for (int j = 1; j <= 4; j++) {
                long long takeWeight = dp[k][j - 1].first + weight;
                vector<int> takeIndices = dp[k][j - 1].second;
                takeIndices.push_back(originalIndex);
                sort(takeIndices.begin(), takeIndices.end());

                pair<long long, vector<int>> take = {takeWeight, takeIndices};

                // Store maximum weight (or lexicographically smaller indices on tie)
                if (take.first > dp[i + 1][j].first) {
                    dp[i + 1][j] = take;
                } else if (take.first == dp[i + 1][j].first && !take.second.empty()) {
                    if (dp[i + 1][j].second.empty() || take.second < dp[i + 1][j].second) {
                        dp[i + 1][j] = take;
                    }
                }
            }
        }

        return dp[n][4].second;
    }
};