#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check(int i, int j, int m, int n) {
        if ( 0 <= i && i < m && 0 <= j && j < n ) return true;
        return false;
    }
    void BFS( int x, int y, int m, int n, vector<vector<int>>& mark, vector<int>& count, vector<vector<int>>& grid) {
        queue<ii> q;
        q.push({x,y});
        int temp = mark[x][y];
        count[temp]++;
        while ( q.size() ) {
            ii u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {dx[i] + u.fi, dy[i] + u.se};
                if ( check(v.fi,v.se,m,n) && mark[v.fi][v.se] == -1 && grid[v.fi][v.se] == 1 ) {
                    mark[v.fi][v.se] = mark[u.fi][u.se];
                    count[temp]++;
                    q.push(v);
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mark(m,vector<int>(n,-1));
        vector<int> count(m*n+1,0);
        int pos = 0;
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) { 
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] == 1 && mark[i][j] == -1 ) {
                    mark[i][j] = pos;
                    pos++;
                    BFS(i,j,m,n,mark,count,grid);
                    ans = max(ans,count[pos-1]);
                }
            }
        }
        vector<int> vis(pos+1,0);
        cout<<1<<'\n';
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] == 0 ) {
                    int res = 1;
                    for ( int k = 0 ; k < 4 ; ++k ) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if ( check(x,y,m,n) && mark[x][y] != -1 && vis[mark[x][y]] == 0 ) {
                            res += count[mark[x][y]];
                            vis[mark[x][y]]++;
                        }
                    }
                    for ( int k = 0 ; k < 4 ; ++k ) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if ( check(x,y,m,n) && mark[x][y] != -1 ) {
                            vis[mark[x][y]] = 0;
                        }
                    }
                    ans = max(ans,res);
                }
            }
        }
        return ans;
    }
};
