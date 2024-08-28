#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    void BFS( vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool& check, ii start, int m, int n ) {
        queue<ii> q;
        q.push({start});
        if ( grid1[start.fi][start.se] == 0 ) check = false;
        grid2[start.fi][start.se] = 0;
        while ( q.size() ) {
            ii u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.fi + dx[i],u.se + dy[i]};
                if ( 0 <= v.fi && v.fi < m && 0 <= v.se && v.se < n && grid2[v.fi][v.se] == 1 ) {
                    if ( grid1[v.fi][v.se] == 0 ) check = false;
                    grid2[v.fi][v.se] = 0;
                    q.push(v);
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid2[i][j] == 1 ) {
                    bool check = true;
                    BFS(grid1,grid2,check,{i,j},m,n);
                    ans += check;
                }
            }
        }
        return ans;
    }
};
