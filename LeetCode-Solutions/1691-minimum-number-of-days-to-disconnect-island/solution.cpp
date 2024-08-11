#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check ( int x, int y, int m, int n ) {
        if ( 0 <= x && x < m && 0 <= y && y < n ) return true;
        return false;
    }
    void BFS(int x, int y, vector<vector<int>> a, int m, int n, vector<vector<int>>& vis ) {
        queue<ii> q;
        q.push({x,y});
        while ( q.size() ) {
            ii u = q.front();
            q.pop();
            vis[u.fi][u.se] = 1;
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.fi+dx[i],u.se+dy[i]};
                if ( check(v.fi,v.se,m,n) && vis[v.fi][v.se] == 0 && a[v.fi][v.se] == 1 ) {
                    q.push(v);
                    vis[v.fi][v.se] = 1;
                }
            }
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num_1 = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                num_1 += (grid[i][j] == 1);
            }
        }
        if ( num_1 <= 1 ) return num_1;
        int count = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] == 1 && vis[i][j] == 0 ) {
                    if ( count != 0 ) {
                        return 0;
                    }
                    count++;
                    BFS(i,j,grid,m,n,vis);
                }
            }
        }
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] == 1) {
                    grid[i][j] = 0;
                    for ( int u = 0 ; u < m ; ++u ) {
                        for ( int v = 0 ; v < n ; ++v ) {
                            vis[u][v] = 0;
                        }
                    }
                    count = 0;
                    for ( int u = 0 ; u < m ; ++u ) {
                        for ( int v = 0 ; v < n ; ++v ) {
                            if ( grid[u][v] == 1 && vis[u][v] == 0 ) {
                                if ( count != 0 ) {
                                    return 1;
                                }
                                count++;
                                BFS(u,v,grid,m,n,vis);
                            }
                        }
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
