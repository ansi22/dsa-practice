class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans=0;
        vector<int> st;
        unordered_map<int, int> cnt;
        for(auto x: nums) {
            while(!st.empty() && st.back()>x) {
                cnt[st.back()]--;
                st.pop_back();
            }
            ans+=st.size()-cnt[x];
            st.push_back(x);
            cnt[x]++;
        }
        return ans;
    }
};