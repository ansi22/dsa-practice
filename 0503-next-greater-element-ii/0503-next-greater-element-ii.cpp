class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        stack<int> st;
        vector<int> ge(n);
        for(int i=2*n-1;i>=0;i--) {
            while(!st.empty()&&a[i%n]>=st.top()) {
                st.pop();
            }
            if(i<n) {
                if(!st.empty()) {
                    ge[i]=st.top();
                } else {
                    ge[i]=-1;
                }
            }
            st.push(a[i%n]);
        }
        return ge;
    }
};