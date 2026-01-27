class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        stack<char> st;
        int ok=0;
        for(auto x: num) {
            while(!st.empty() && st.top()>x && k>0) {
                st.pop();
                k--;
            }
            st.push(x);
        }

        while(k>0&&!st.empty()) {
            st.pop();
            k--;
        }

        while(!st.empty()) {
            s+=st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());
        ok=s.length();

        for(int i=0;i<s.length();i++) {
            if(s[i]!='0') {
                ok=i;
                break;
            }
        }
        // return s;
        // cout<<s<<" "<<ok<<"\n";

        return ok==s.length()?"0":s.substr(ok);
    }
};