class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> v;

        for(auto x: strs) {
            string s=x;
            sort(s.begin(), s.end());
            mp[s].push_back(x);
        }

        for(auto x: mp) {
            v.push_back(x.second);
        }

        return v;
    }
};

/*
 strs = ["eat","tea","tan","ate","nat","bat"]
*/