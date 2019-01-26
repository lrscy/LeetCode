auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int fa[1010];
    
    int find( int x ) { return fa[x] == x ? x : fa[x] = find( fa[x] ); }
    void munion( int x, int y ) { fa[find( y )] = find( x ); }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for( int i = 0; i < 1010; ++i ) fa[i] = i;
        int cnt = 0;
        for( int i = 0; i < edges.size(); ++i ) {
            if( find( edges[i][1] ) == find( edges[i][0] ) ) { cnt = i; continue; }
            munion( edges[i][0], edges[i][1] );
        }
        return edges[cnt];
    }
};
