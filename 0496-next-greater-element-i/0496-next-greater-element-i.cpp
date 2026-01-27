class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int m=a.size(), n=b.size();
        map<int, int> mp;
        stack<int> st;

        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push(b[i]);
            } else {
                while(!st.empty()&&st.top()<b[i]) {
                    mp[st.top()]=b[i];
                    st.pop();
                }
            }
            st.push(b[i]);
        }

        while(!st.empty()) {
            mp[st.top()]=-1;
            st.pop();
        }

        for(int i=0;i<m;i++) {
            a[i]=mp[a[i]];
        }

        return a;
    }
};