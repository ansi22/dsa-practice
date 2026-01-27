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

    int maximalRectangle(vector<vector<char>>& a) {
        int m=a.size(), n=a[0].size(), maxi=0;
        if(m==0) {
            return 0;
        }

        vector<int> h(n,0);

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(a[i][j]=='1') {
                    h[j]++;
                } else {
                    h[j]=0;
                }
            }
            maxi=max(maxi, largestRectangleArea(h));
        }

        return maxi;

    }
};