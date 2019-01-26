auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int len = quality.size();
        vector<pair<double, int>> vec;
        double ret = ( 1 << 31 ) - 1;
        for( int i = 0; i < len; ++i ) {
            vec.push_back( make_pair( 1. * wage[i] / quality[i], quality[i] ) );
        }
        sort( vec.begin(), vec.end() );
        priority_queue<int> pq;
        int sum = 0;
        for( auto &v : vec ) {
            pq.push( v.second );
            sum += v.second;
            if( pq.size() > K ) sum -= pq.top(), pq.pop();
            if( pq.size() == K ) ret = min( ret, v.first * sum );
        }
        return ret;
    }
};
