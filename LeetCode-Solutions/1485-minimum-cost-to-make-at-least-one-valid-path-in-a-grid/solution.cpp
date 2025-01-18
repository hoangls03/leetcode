#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
class Solution {
public:
    bool check( int i, int j, int m, int n ) {
        if ( 0 <= i && i < m && 0 <= j && j < n ) {
            return true;
        }
        return false;
    }
    int minCost(vector<vector<int>>& grid) {
        queue<ii> q;
        q.push({0,0});
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,1e9));
        vis[0][0] = 0;
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.fi + dx[i],u.se + dy[i]};
                int cost = 1;
                if ( grid[u.fi][u.se] == i + 1 ) {
                    cost = 0;
                }
                if ( check(v.fi,v.se,m,n) && vis[v.fi][v.se] > vis[u.fi][u.se] + cost ) {
                    vis[v.fi][v.se] = vis[u.fi][u.se] + cost;
                    q.push({v.fi,v.se});
                }
            }
        }
        return vis[m-1][n-1];
    }
};
