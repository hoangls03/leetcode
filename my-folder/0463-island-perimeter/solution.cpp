const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( int u, int v, int m , int n ) {
        if ( 0 <= u && u < m && 0 <= v && v < n ) return true;
        return false; 
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] == 1 ) {
                    for ( int z = 0 ; z < 4 ; ++z ) {
                        int u_new = i + dx[z];
                        int v_new = j + dy[z];
                        if ( !check(u_new,v_new,m,n) ) ans++;
                        else if ( grid[u_new][v_new] == 0 ) ans++;
                    }
                }
            }
        }
        return ans;
    }
};
