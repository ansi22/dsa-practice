class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k) return "0";
        int n=num.length();
        stack<char> stk;
        for(auto c: num) {
            while(k>0&&!stk.empty()&&c<stk.top()){
                stk.pop();
                k--;
            }
            if(!stk.empty()||c!='0') 
                stk.push(c);
        }
            while(!stk.empty()&&k--) 
                stk.pop();
            if(stk.empty())
                return "0";
            string s="";
            while(!stk.empty()) {
                s.push_back(stk.top());
                stk.pop();
            }
        reverse(s.begin(),s.end());
        return s;
    }
};