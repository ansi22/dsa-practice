class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int maxi=0, n=h.size();

        for(int i=0;i<=n;i++) {
            while(!st.empty()&&(i==n||h[st.top()]>=h[i])) {
                int height=h[st.top()];
                st.pop();
                int width=st.empty()?i:(i-st.top()-1);
                int area=width*height;
                if(area>maxi){
                    maxi=area;
                }
            }
            st.push(i);
        }
        return maxi;
    }
};