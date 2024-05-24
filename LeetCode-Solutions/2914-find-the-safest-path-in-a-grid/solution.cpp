#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( int u, int v, int m, int n ) {
        if ( u < 0 || u >= m || v < 0 || v >= n ) return false;
        return true;
    }
    void find_thieve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& d) {
        queue<ii> q;

        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                d[i][j] = -1;
                if ( grid[i][j] ==  1 ) {
                    q.push({i,j});
                    d[i][j] = 0;
                }
            }
        }
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                int u_new = u.fi + dx[i];
                int v_new = u.se + dy[i];
                if ( check(u_new,v_new,m,n) && d[u_new][v_new] == -1 ) {
                    d[u_new][v_new] = d[u.fi][u.se] + 1;
                    q.push({u_new,v_new});
                }
            }
        }
    }
    bool find_path(int m, int n, int k, vector<vector<int>>& grid, vector<vector<int>>& d) {
        queue<ii> q;
        if ( k <= d[0][0] ) {
            q.push({0,0});
        }
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        while ( q.size() ) {
            ii u = q.front();
           
            q.pop();
            visited[u.fi][u.se] = true;
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.fi+dx[i],u.se+dy[i]};
                if ( check(v.fi,v.se,m,n) && !visited[v.fi][v.se] && d[v.fi][v.se] >= k ) {
                    q.push(v);
                    visited[v.fi][v.se] = true;
                }
            }
        }
        return visited[m-1][n-1];
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> d(m,vector<int>(n));
        find_thieve(m,n,grid,d);
        int l = 0;
        int r = 810;
        int ans = 0;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            if ( find_path(m,n,mid,grid,d) ) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
