class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int st=0, en=n-1, ans=0;
        int maxst=0, maxen=0;

        while(st<=en) {
            maxst=max(height[st], maxst);
            maxen=max(height[en], maxen);

            if(height[st]<height[en]) {
                ans+=abs(maxst-height[st]);
                st++;
            } else {
                ans+=abs(maxen-height[en]);
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