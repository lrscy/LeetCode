class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        int inv[1 << 16] = { 0 };
        for( auto a : A ) {
            for( int i = 0; i < ( 1 << 16 ); ++i )
                if( ( a & i ) == 0 )
                    ++inv[i];
        }
        int ret = 0;
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < n; ++j ) {
                ret += inv[A[i] & A[j]];
            }
        }
        return ret;
    }
};
