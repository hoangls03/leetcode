#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( int x, int y, int n) {
        if ( 0 <= x && x < n && 0 <= y && y < n ) return true;
        return false;
    }
    void BFS(vector<vector<int>>& time, int n,vector<vector<int>>& grid) {
        queue<ii> q;
        q.push({0,0});
        time[0][0] = grid[0][0];
        while ( q.size() ) {
            ii u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                int x = u.fi + dx[i];
                int y = u.se + dy[i];
                if ( check(x,y,n) ) {
                    if ( max(grid[x][y],time[u.fi][u.se]) < time[x][y] ) {
                        time[x][y] = max(grid[x][y],time[u.fi][u.se]);
                        q.push({x,y});
                    }
                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> time(n,vector<int>(n,10000));
        BFS(time,n,grid);
        return time[n-1][n-1];
    }
};
