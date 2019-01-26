class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ret = 0, len = s.length();
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        if( s.size() <= 2 ) return s.size();
        while( j < len ) {
            mp[s[j]] = j;
            if( mp.size() > 2 ) {
                ret = max( ret, j - i );
                while( mp.size() > 2 ) {
                    int key, n = INT_MAX;
                    for( auto it = mp.begin(); it != mp.end(); ++it ) {
                        if( it->second < n ) {
                            n = it->second;
                            key = it->first;
                        }
                    }
                    i = n + 1;
                    mp.erase( key );
                }
            }
            ++j;
        }
        ret = max( ret, j - i );
        return ret;
    }
};
