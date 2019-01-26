/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        long long prob[10][30] = { 0 };
        for( auto &w : wordlist ) {
            for( int i = 0; i < 6; ++i ) prob[i][w[i] - 'a'] += 1;
        }
        while( true ) {
            string tmp = generate( prob, wordlist );
            int ret = master.guess( tmp );
            if( ret == tmp.length() ) break;
            for( auto it = wordlist.begin(); it != wordlist.end(); ) {
                if( match( *it, tmp ) != ret ) {
                    for( int i = 0; i < 6; ++i )
                        prob[i][( *it )[i] - 'a'] -= 1;
                    wordlist.erase( it );
                } else ++it;
            }
        }
        return ;
    }
    
    string generate( long long prob[][30], vector<string>& wordlist ) {
        string ret;
        long long best = 0;
        for( auto w : wordlist ) {
            long long tpscore = 1;
            for( int i = 0; i < 6; ++i ) tpscore *= prob[i][w[i] - 'a'];
            if( tpscore > best ) {
                best = tpscore;
                ret = w;
            }
        }
        return ret;
    }
    
    int match( string a, string b ) {
        int ret = 0;
        for( int i = 0; i < a.length(); ++i ) {
            if( a[i] == b[i] ) ++ret;
        }
        return ret;
    }
};
