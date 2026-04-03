class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x: s){
            if(x=='('||x=='{'||x=='[') st.push(x);
            else{
                if(x==')'||x=='}'||x==']'){
                    if(st.empty()) return 0;
                    else{
                        char y=st.top();
                        st.pop();
                        if((x==')'&&y=='(')||(x=='}'&&y=='{')||(x==']'&&y=='[')){
                            continue;
                        }
                        return 0;
                    }
                }
            }
        }
        return st.empty();
    }
};

/*

{[]}
{[
x=[
y=]
{
*/ 