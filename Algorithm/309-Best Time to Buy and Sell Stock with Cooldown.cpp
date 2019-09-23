class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        //s0 denote maxprofit at i-th day without stock
        //s1 denote maxprofit at i-th day with stock
        //s2 denote maxprofit at i-th day when cooling down.
        //s0 could be transited from s0 at i-1th day (do nothing), or from s1 at i-1th day (sell)
        //s1 could be transited from s1 at i-1th day (do nothing), or from s2 at i-1th day (cool to buy)
        //s2 could be transited from s2 at i-1th day (do nothing), or from s0 at i-1th day (do nothing)
        int s0 = 0, s1 = -1e9, s2 = 0;
        for(const auto &p: prices) {
            int tmp = s0;
            s0 = max(s0, s1 + p);
            s1 = max(s1, s2 - p);
            s2 = max(s2, tmp);
        }
        return max(s0, s2);
    }
};
