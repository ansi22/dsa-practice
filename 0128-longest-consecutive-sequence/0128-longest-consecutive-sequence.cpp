class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi=0;
        for(int x: st) {
            if(st.find(x-1)==st.end()) {
                int len=1;
                while(st.find(x+len)!=st.end()) {
                    len++;
                }
                maxi=max(maxi, len);
            }
        }

        return maxi;
    }
};

