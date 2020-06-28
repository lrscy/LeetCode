class Solution {
public:
    unordered_map<string, vector<pair<string, bool>>> ump;
    int tot = 0;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ret;
        tot = tickets.size();
        if(!tot) return ret;
        ret.push_back("JFK");
        for(auto &t: tickets) {
            if(!ump.count(t[0])) ump[t[0]] = vector<pair<string, bool>>();
            ump[t[0]].push_back({t[1], false});
        }
        for(auto it = ump.begin(); it != ump.end(); ++it) {
            sort(it->second.begin(), it->second.end());
        }
        dfs(ret, 0);
        return ret;
    }
    
    bool dfs(vector<string> &v, int n) {
        if(n == tot) return true;
        string s = v.back();
        if(!ump.count(s)) return false;
        for(auto it = ump[s].begin(); it != ump[s].end(); ++it) {
            if(!it->second) {
                it->second = true;
                v.push_back(it->first);
                if(dfs(v, n + 1)) return true;
                v.pop_back();
                it->second = false;
            }
        }
        return false;
    }
};

