class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        vector<int> day( n + 10 );
        int dmin = INT_MAX;
        for( int i = 0; i < n; ++i ) day[flowers[i]] = i + 1;
        for( int i = 1; i <= n; ++i ) {
            int lo, hi;
            int flag = 2;
            if( i - k <= 1 ) {
                lo = i + 1;
                --flag;
            } else {
                lo = i - k;
                if( day[i - k - 1] > day[i] ) {
                    --flag;
                    lo = i + 1;
                }
            }
            if( i + k >= n ) {
                hi = i - 1;
                --flag;
            } else {
                hi = i + k;
                if( day[i + k + 1] > day[i] ) {
                    --flag;
                    hi = i - 1;
                }
            }
            for( int j = lo; flag > 0 && j <= hi; ++j ) if( day[j] < day[i] ) flag = 0;
            if( flag > 0 ) dmin = min( dmin, day[i] );
        }
        return dmin == INT_MAX ? -1 : dmin;
    }
};
