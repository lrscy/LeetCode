class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[400][5];
        map<int, int> mp;
        memset( dp, 0x3F, sizeof( dp ) );
        dp[366][0] = 0;
        for( auto it = days.begin(); it != days.end(); ++it ) mp[*it] = *it;
        for( int i = 365; i >= 1; --i ) {
            auto it = mp.lower_bound( i );
            if( i <= 365 ) dp[i][0] = ( mp.count( i ) ) ? min( dp[i +  1][0], min( dp[i +  1][1], dp[i +  1][2] ) ) + costs[0] : dp[i + 1][0];
            if( i <= 358 ) dp[i][1] = ( mp.count( i ) ) ? min( dp[i +  7][0], min( dp[i +  7][1], dp[i +  7][2] ) ) + costs[1] : dp[i + 1][1];
            if( i <= 335 ) dp[i][2] = ( mp.count( i ) ) ? min( dp[i + 30][0], min( dp[i + 30][1], dp[i + 30][2] ) ) + costs[2] : dp[i + 1][2];
        }
        return min( dp[1][0], min( dp[1][1], dp[1][2] ) );
    }
};
