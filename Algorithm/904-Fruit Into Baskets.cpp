static const int desync_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i = 0, j = 0, n = tree.size();
        int cnt = 0, sum = 0;
        map<int, int> mp;
        while( i < n && j < n ) {
            cnt = max( cnt, sum );
            mp[tree[j]]++; sum += 1; ++j;
            while( mp.size() > 2 && i < j ) {
                --mp[tree[i]]; --sum;
                if( mp[tree[i]] == 0 ) mp.erase( tree[i] );
                ++i;
            }
        }
        cnt = max( cnt, sum );
        return cnt;
    }
};
