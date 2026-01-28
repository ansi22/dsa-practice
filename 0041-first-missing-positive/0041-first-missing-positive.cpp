class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool> seen(n+1, 0);

        for(auto x: nums) {
            if(x>0 and x<=n) {
                seen[x]=1;
            }
        }

        for(int i=1;i<=n;i++) {
            if(!seen[i]) {
                return i;
            }
        }

        return n+1;
    }
};