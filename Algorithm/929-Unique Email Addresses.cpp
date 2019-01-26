static int desyncio = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for( vector<string>::iterator sit = emails.begin(); sit != emails.end(); ++sit ) {
            string::iterator iter;
            string str = "";
            int flag = 0;
            for( iter = sit->begin(); iter != sit->end(); ++iter ) {
                if( *iter == '@' ) break;
                if( flag == 1 ) continue;
                if( *iter == '+' ) { flag = 1; continue; }
                if( *iter == '.' ) continue;
                str += *iter;
            }
            str += sit->substr( iter - sit->begin() );
            s.insert( str );
        }
        return s.size();
    }
};
