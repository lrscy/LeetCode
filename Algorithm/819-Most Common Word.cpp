static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string str, ret;
        map<string, int> mp, ban;
        transform( paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower );
        int cnt = 0, pos = 0;
        for( auto it = banned.begin(); it != banned.end(); ++it ) ban[*it] = 1;
        while( ( str = getStr( paragraph, pos ) ) != "" ) {
            if( !ban.count( str ) ) {
                ++mp[str];
                if( mp[str] > cnt ) {
                    cnt = mp[str];
                    ret = str;
                }
            }
        }
        return ret;
    }
    
    string getStr( string& str, int& pos ) {
        if( pos >= str.length() ) return "";
        int s = pos;
        while( str[s] < 'a' || str[s] > 'z' ) ++s;
        int e = s;
        while( 'a' <= str[e] && str[e] <= 'z' ) ++e;
        pos = e;
        while( ( str[pos] < 'a' || str[pos] > 'z' ) && pos < str.length() ) ++pos;
        return str.substr( s, e - s );
    }
};
