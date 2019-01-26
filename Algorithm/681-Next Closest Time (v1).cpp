class Solution {
public:
    vector<int> nums;
    string nextClosestTime(string time) {
        vector<int> v;
        int len = 0;
        for( int i = 0; i < time.length(); ++i ) {
            if( time[i] != ':' ) {
                v.push_back(time[i] - '0' );
                nums.push_back(time[i] - '0' );
                ++len;
            }
        }
        sort( nums.begin(), nums.end() );
        next( v, len - 1 ); 
        int a = v[0] * 10 + v[1], b = v[2] * 10 + v[3];
        string s = "";
        for( int i = 0; i < len; ++i ) {
            s += v[i] + '0';
            if( i == 1 ) s += ':';
        }
        return s;
    }
    
    void next( vector<int> &v, int pos ) {
        int tp = std::upper_bound( nums.begin(), nums.end(), v[pos] ) - nums.begin();
        if( nums[tp] <= v[pos] ) {
            if( pos ) next( v, pos - 1 );
            v[pos] = nums[0];
        }
        else {
            v[pos] = nums[tp];
            if( pos == 2 ) {
                int a = v[pos] * 10 + v[pos + 1];
                if( a >= 60 ) {
                    next( v, pos - 1 );
                    v[pos] = nums[0];
                }
            }
            if( pos == 1 ) {
                int a = v[pos - 1] * 10 + v[pos];
                if( a >= 24 ) {
                    next( v, pos - 1 );
                    v[pos] = nums[0];
                }
            }
            if( pos == 0 ) {
                int a = v[pos] * 10 + v[pos + 1];
                if( a >= 24 ) v[pos] = nums[0];
            }
        }
    }
};
