static const int desync_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        bool flag = true;
        int c1 = 0, c2 = 0;
        for( auto it = S.begin(); it != S.end(); ++it ) {
            if( *it == '#' ) c1 = max( c1 - 1, 0 );
            else S[c1++] = *it;
        }
        for( auto it = T.begin(); it != T.end(); ++it ) {
            if( *it == '#' ) c2 = max( c2 - 1, 0 );
            else T[c2++] = *it;
        }
        if( c1 != c2 ) flag = false;
        else {
            for( int i = 0; i < c1; ++i ) {
                if( S[i] != T[i] ) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};
