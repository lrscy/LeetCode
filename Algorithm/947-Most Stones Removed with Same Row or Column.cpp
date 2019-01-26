int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int fa[20010];
    map<int, int> mp;

    int find( int x ) { return fa[x] == x ? x : fa[x] = find( fa[x] ); }
    void munion( int x, int y ) { fa[find(x)] = find( y ); }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for( int i = 0; i < 20010; ++i ) fa[i] = i;
        for( int i = 0; i < stones.size(); ++i ) {
            munion( stones[i][0], stones[i][1] + 10000 );
        }
        set<int> st;
        for( int i = 0; i < stones.size(); ++i ) {
            st.insert( find( stones[i][0] ) );
        }
        return n - st.size();
    }
};
