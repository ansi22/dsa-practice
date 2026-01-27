class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;

        for(int x: a) {
            if(x>0) {
                st.push(x);
            } else {
                while(!st.empty() && st.top()>0 && st.top()<-x) {
                    st.pop();
                }

                if(st.empty() || st.top()<0) {
                    st.push(x);
                }

                if(!st.empty() && st.top()==-x) {
                    st.pop();
                }
            }
        }

        vector<int> res;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};