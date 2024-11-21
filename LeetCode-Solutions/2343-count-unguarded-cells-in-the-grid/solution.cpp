const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( int i, int j, int m, int n) {
        if ( 0 <= i && i < m && 0 <= j && j < n ) return true;
        return false;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mark(m,vector<int>(n,0));
        for ( auto g : guards ) {
            mark[g[0]][g[1]] = 2;
        }
        for ( auto w : walls ) {
            mark[w[0]][w[1]] = 2;
        }
        for ( auto g : guards ) {
            for ( int i = 0 ; i < 4 ; ++i ) {
                int x = g[0];
                int y = g[1];
                
                while ( check(x + dx[i],y + dy[i],m,n) && mark[x+dx[i]][y+dy[i]] != 2 ) {
                    x += dx[i];
                    y += dy[i];
                    
                    mark[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                ans += ( mark[i][j] == 0 );
            }
        }
        return ans;
    }
};
