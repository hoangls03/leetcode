#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( int i, int j, int m, int n ) {
        if ( 0 <= i && i < m && 0 <= j && j < n ) return true;
        return false;
    }
    void BFS( int i, int j, int m, int n, vector<vector<int>>& grid, int& ans) {
        queue<ii> q;
        q.push({i,j});
        ans += grid[i][j];
        grid[i][j] = 0;
        while ( q.size() ) {
            ii u = q.front();
            q.pop();
            for ( int k = 0 ;  k < 4 ; ++k ) {
                ii v = {u.fi + dx[k],u.se + dy[k]};
                if ( check(v.fi,v.se,m,n) && grid[v.fi][v.se] != 0 ) {
                    ans += grid[v.fi][v.se];
                    grid[v.fi][v.se] = 0;
                    q.push(v);
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] != 0 ) {
                    int sum = 0;
                    BFS(i,j,m,n,grid,sum);
                    cout<<'\n';
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};
