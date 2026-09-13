vector<long long> parity[2];
    int func=[]() {
        long long inf=1e9;
        for(int i=1;i<100000;i++) {
            string s=to_string(i);
            string r=s;
            reverse(r.begin(), r.end());
            long long a1=stoll(s.substr(0, s.size()-1)+r);
            long long a2=stoll(s+r);
            if(a1<inf) parity[a1&1].push_back(a1);
            if(a2<inf) parity[a2&1].push_back(a2);
        }
        sort(parity[0].begin(), parity[0].end());
        sort(parity[1].begin(), parity[1].end());
        return 0;
    }();
class Solution {
public:
    
    long long minOperations(vector<int>& nums) {
        // func();
        long long res=0;

        for(auto x: nums) {
            auto& p=parity[x&1];
            int i=lower_bound(p.begin(), p.end(), x)-p.begin();
            if(i>=p.size()) {
                i=p.size()-1;
            }
            long long d1=abs(x-p[i]);
            long long d2=i>0?abs(x-p[i-1]):d1;
            res+=min(d1, d2)/2;
        }

        return res;
    }
};