static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        char c[80000] = "";
        int cnt = 0, cnt2 = 0;
        for( auto rit = S.rbegin(); rit != S.rend(); ++rit ) {
            if( *rit == '-' ) continue;
            if( cnt2 && cnt2 % K == 0 ) c[cnt++] = '-';
            c[cnt++] = toupper( *rit ), ++cnt2;
        }
        std::reverse( c, c + cnt );
        return c;
    }
};
