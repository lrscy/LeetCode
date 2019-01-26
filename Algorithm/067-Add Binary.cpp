class Solution {
public:
    string addBinary(string a, string b) {
        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );
        int la = a.length(), lb = b.length(), lc = min( la, lb ), d = 0;
        if( la < lb ) swap( a, b ), swap( la, lb );
        for( int i = 0; i < la; ++i ) {
            int da = a[i] - '0', db = b[i] - '0';
            int num = da + d + ( i < lc ? db : 0 );
            if( num > 1 ) { d = 1; num &= 1; }
            else d = 0;
            a[i] = num + '0';
        }
        if( d ) a += "1";
        reverse( a.begin(), a.end() );
        return a;
    }
};
