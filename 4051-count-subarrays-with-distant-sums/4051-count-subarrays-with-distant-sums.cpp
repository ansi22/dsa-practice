struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n=n;
        bit.assign(n+1, 0);
    }

    void add(int idx, int delta) {
        for(;idx<=n;idx+=idx&-idx) {
            bit[idx]+=delta;
        }
    }

    int sum(int l, int r) {
        return sum(r)-sum(l);
    }

    int sum(int r) {
        int ans=0;
        for(;r>0;r-=r&-r) {
            ans+=bit[r];
        }
        return ans;
    }
};

class Solution {
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        long long n=nums.size();
        if(k==0) {
            return n*(n+1)/2;
        }
        vector<long long> p={0};
        long long cur=0;
        for(auto x: nums) {
            cur+=x;
            p.push_back(cur);
        }
        vector<long long> s=p;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());

        int m=s.size();
        FenwickTree bit(m);
        long long ans=0;
        int tot=0;

        for(long long x: p) {
            int idx1=upper_bound(s.begin(), s.end(), x-goal-k)-s.begin();
            ans+=bit.sum(idx1);

            int idx2=lower_bound(s.begin(), s.end(), x-goal+k)-s.begin();
            ans+=tot-bit.sum(idx2);

            int idx=lower_bound(s.begin(), s.end(), x)-s.begin()+1;
            bit.add(idx, 1);
            tot++;
        }

        return ans;
    }
};
