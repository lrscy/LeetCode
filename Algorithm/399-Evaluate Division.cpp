class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, map<string, double>> mp;
        vector<double> ret;
        for( int i = 0; i < equations.size(); ++i ) {
            string s1, s2;
            s1 = equations[i].first;
            s2 = equations[i].second;
            if( !mp.count( s1 ) ) {
                map<string, double> tmp;
                mp[s1] = tmp;
            }
            if( !mp.count( s2 ) ) {
                map<string, double> tmp;
                mp[s2] = tmp;
            }
            mp[s1][s2] = values[i];
            mp[s2][s1] = 1 / values[i];
        }
        for( auto &q: queries ) {
            if( !mp.count( q.first ) || !mp.count( q.second ) ) {
                ret.push_back( -1 );
                continue;
            }
            priority_queue<pair<double, string>> pq;
            map<string, bool> tm;
            pq.push( make_pair( 1.0, q.first ) ); tm[q.first] = true;
            bool flag = false;
            while( !pq.empty() ) {
                auto tmp = pq.top(); pq.pop();
                tm[tmp.second] = true;
                if( tmp.second == q.second ) {
                    ret.push_back( tmp.first );
                    flag = true;
                    break;
                } else {
                    for( auto &v : mp[tmp.second] ) {
                        if( tm[v.first] ) continue;
                        pq.push( make_pair( tmp.first * v.second, v.first ) );
                    }
                }
            }
            if( !flag ) ret.push_back( -1 );
        }
        return ret;
    }
};
