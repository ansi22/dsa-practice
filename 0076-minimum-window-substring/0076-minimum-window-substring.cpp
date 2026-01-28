class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) {
            return "";
        }

        unordered_map<char, int> mp;

        for(char ch: t) {
            mp[ch]++;
        }

        int mini=INT_MAX;
        int st=0, req=t.length(), i=0, j=0, n=s.length();

        while(j<n) {
            char ch=s[j];
            if(mp[ch]>0) {
                req--;
            }
            mp[ch]--;
            while(req==0) {
                int cur=j-i+1;
                if(mini>cur) {
                    mini=cur;
                    st=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) {
                    req++;
                }
                i++;
            }
            j++;
        }

        return mini==INT_MAX?"":s.substr(st, mini);
    }
};