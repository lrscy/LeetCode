auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
    int nx, ny;
    
    void bfs( vector<vector<char>>& grid, int x, int y ) {
        queue<pair<int, int>> q;
        q.push( make_pair( x, y ) );
        grid[x][y] = '0';
        while( !q.empty() ) {
            auto tmp = q.front(); q.pop();
            for( int i = 0; i < 4; ++i ) {
                int tx = tmp.first + dx[i], ty = tmp.second + dy[i];
                if( tx < 0 || tx >= nx || ty < 0 || ty >= ny ) continue;
                if( grid[tx][ty] == '1' ) {
                    grid[tx][ty] = '0';
                    q.push( make_pair( tx, ty ) );
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        nx = grid.size();
        if( nx ) ny = grid[0].size();
        for( int i = 0; i < nx; ++i ) {
            for( int j = 0; j < ny; ++j ) {
                if( grid[i][j] == '1' ) {
                    ++ret;
                    bfs( grid, i, j );
                }
            }
        }
        return ret;
    }
};
