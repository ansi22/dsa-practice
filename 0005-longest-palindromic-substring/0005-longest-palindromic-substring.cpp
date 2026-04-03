class Solution {
public:
    bool dp[1001][1001];
    string longestPalindrome(string s) {
        int n=s.size();
        int len=1, st=0;

        // dp[i][i]=1
        for(int i=0;i<n;i++) {
            dp[i][i]=1;
        }

        // first fill the cache to 1 for length 2
        for(int i=0;i<n;i++) {
            if(s[i]==s[i+1]) {
                dp[i][i+1]=1;
                len=2;
                st=i;
            }
        }

        // for length 3 onwards, check if boundary chars are equal and innner chars have cache 1, and track of max length and starting indexes.
        for(int k=3;k<=n;k++) { // length of substring
            for(int i=0;i<n-k+1;i++) { // starting index
                int j=i+k-1;
                if(dp[i+1][j-1]&&s[i]==s[j]) {
                    dp[i][j]=1;
                    if(k>len) {
                        len=k;
                        st=i;
                    }
                }
            }
        }

        // cout<<st<<" "<<n<<" "<<len<<"\n";
        string ans="";
        for(int i=st;i<n&&len;i++,len--) {
            ans+=s[i];
        }

        return ans;
    }
};