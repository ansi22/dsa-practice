class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache;
        for(auto x: nums) {
            auto it=lower_bound(cache.begin(), cache.end(), x);
            if(it==cache.end()) {
                cache.push_back(x);
            } else {
                *it=x;
            }
        }
        return cache.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>&a1, const vector<int>&a2){
            if(a1[0]==a2[0]) {
                return a1[1]>a2[1];
            }
            return a1[0]<a2[0];
        });

        vector<int> height(envelopes.size());
        for(int i=0;i<envelopes.size();i++) {
            height[i]=envelopes[i][1];
        }

        return lengthOfLIS(height);
    }
};

// lis