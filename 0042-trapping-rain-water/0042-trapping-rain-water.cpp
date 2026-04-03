class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int st=0, en=n-1, ans=0;
        int maxst=0, maxen=0;

        while(st<=en) {
            maxst=max(h[st], maxst);
            maxen=max(h[en], maxen);

            if(h[st]<h[en]) {
                ans+=abs(maxst-h[st]);
                st++;
            } else {
                ans+=abs(maxen-h[en]);
                en--;
            }
        }

        return ans;
    }
};

/*
 Here the formula is at any i, min(max_prefix[i], max_suffix[i])-a[i];
 but the catch here is at any given i we have to consider any of max_prefix or max_suffix
*/
