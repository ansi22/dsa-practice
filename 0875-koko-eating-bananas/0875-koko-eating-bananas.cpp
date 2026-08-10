class Solution {
public:
    bool check(vector<int>& piles, int mid, int h) {
        long z=0;
        for(auto x: piles) {
            int y=x/mid;
            z+=y;
            z+=x%mid!=0;
        }
        return z<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int st=1, en=*max_element(piles.begin(), piles.end());

        while(st<=en) {
            int mid=st+(en-st)/2;
            if(check(piles, mid, h)) {
                en=mid-1;
            } else {
                st=mid+1;
            }
        }

        return st;
    }
};