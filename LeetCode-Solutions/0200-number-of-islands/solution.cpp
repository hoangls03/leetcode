#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

class Solution {
public:
    bool check ( int u, int v, int m, int n ) {
        if ( 0 <= u && u < m && 0 <= v && v < n ) return true;
        return false;
    }
    void BFS( int u, int v, vector<vector<char>>& grid, int &ans ) {
        ans++;
        queue<ii> q;
        q.push({u,v});
        int m = grid.size();
        int n = grid[0].size(); 
        while ( q.size() ) {
            u = q.front().fi;
            v = q.front().se;
            grid[u][v] = '0';
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                int u_new = u + dx[i];
                int v_new = v + dy[i];
                if ( check(u_new,v_new,m,n) && grid[u_new][v_new] == '1') {
                    q.push({u_new,v_new});
                    grid[u_new][v_new] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] == '1' ) {
                    BFS(i,j,grid,ans);
                }
            }
        }
        return ans;
    }
};
