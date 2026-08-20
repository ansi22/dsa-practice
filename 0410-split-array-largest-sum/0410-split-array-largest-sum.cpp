class Solution {
public:
    int minsureq(vector<int>& nums, int maxu) {
        int cur=0, splitreq=0;

        for(auto x: nums) {
            if(cur+x<=maxu) {
                cur+=x;
            } else {
                cur=x;
                splitreq++;
            }
        }
        
        return splitreq+1;
    }
    int splitArray(vector<int>& nums, int k) {
        int su=0, maxi=INT_MIN;
        for(auto x: nums) {
            su+=x;
            maxi=max(maxi, x);
        }

        int st=maxi, en=su, minlsu=0;
        while(st<=en) {
            int maxu=st+(en-st)/2;
            if(minsureq(nums, maxu)<=k) {
                en=maxu-1;
                minlsu=maxu;
            } else {
                st=maxu+1;
            }
        }

        return minlsu;
    }
};