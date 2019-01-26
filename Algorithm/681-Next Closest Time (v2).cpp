class Solution {
public:
    string nextClosestTime(string time) {
        map<int, int> nums;
        int mm = 0;
        nums[time[0] - '0'] = 1; nums[time[1] - '0'] = 1; nums[time[3] - '0'] = 1; nums[time[4] - '0'] = 1;
        mm = ( time[0] - '0' ) * 60 * 10 + ( time[1] - '0' ) * 60 + ( time[3] - '0' ) * 10 + ( time[4] - '0' );
        int tm = mm, h1, h2, h3, h4, md = INT_MAX;
        string s = "";
        while( true ) {
            tm = ( tm + 1 ) % ( 24 * 60 );
            if( tm == mm ) break;
            h1 = tm / 60 / 10;
            h2 = tm / 60 % 10;
            h3 = tm % 60 / 10;
            h4 = tm % 60 % 10;
            if( nums[h1] && nums[h2] && nums[h3] && nums[h4] ) {
                string tmp = "";
                s = tmp + char( h1 + '0' ) + char( h2 + '0' ) + ':' + char( h3 + '0' ) + char( h4 + '0' );
                break;
            }
        }
        return s == "" ? time : s;
    }

};
