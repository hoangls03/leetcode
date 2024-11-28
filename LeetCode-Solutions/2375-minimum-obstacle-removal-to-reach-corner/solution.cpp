#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( int i, int j, int m, int n) {
        if ( 0 <= i && i < m && 0 <= j && j < n ) return true;
        return false;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<ii> q;
        vector<vector<int>> d(m,vector<int>(n,0));
        d[0][0] = 1;
        q.push({0,0});
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.fi+dx[i],u.se + dy[i]};
                if ( check(v.fi,v.se,m,n) && ( d[v.fi][v.se] > d[u.fi][u.se] + grid[v.fi][v.se] || d[v.fi][v.se] == 0 ) ) {
                    d[v.fi][v.se] = d[u.fi][u.se] + grid[v.fi][v.se];
                    q.push(v);
                }
            }
        }
        return d[m-1][n-1] - 1;
    }
};
