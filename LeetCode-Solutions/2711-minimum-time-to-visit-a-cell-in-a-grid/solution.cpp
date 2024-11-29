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
    int cost( int u, int v ) {
        if ( u + 1 >= v ) return u + 1;
        return v + ( (v-u) % 2 == 0 );
    }
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> d(m,vector<int>(n,-1));
        queue<ii> q;
        d[0][0] = 0;
        if ( grid[0][1] > 1 && grid[1][0] > 1) return -1;
        q.push({0,0});
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.fi+dx[i],u.se+dy[i]};
                if ( check(v.fi,v.se,m,n) && (d[v.fi][v.se] == -1 || d[v.fi][v.se] > cost(d[u.fi][u.se],grid[v.fi][v.se]) )) {
                    d[v.fi][v.se] = cost(d[u.fi][u.se],grid[v.fi][v.se]);
                    q.push({v.fi,v.se});
                }
            }
        }
        return d[m-1][n-1];
    }
};
