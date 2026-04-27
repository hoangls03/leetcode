#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        bool dir[5][10][10];
        dir[1][1][1] = true;
        dir[1][1][4] = true;
        dir[1][1][6] = true;
        dir[2][1][1] = true;
        dir[2][1][3] = true;
        dir[2][1][5] = true;
        dir[0][2][2] = true;
        dir[0][2][3] = true;
        dir[0][2][4] = true;
        dir[3][2][2] = true;
        dir[3][2][5] = true;
        dir[3][2][6] = true;
        dir[1][3][1] = true;
        dir[1][3][4] = true;
        dir[1][3][6] = true;
        dir[3][3][2] = true;
        dir[3][3][5] = true;
        dir[3][3][6] = true;
        dir[2][4][1] = true;
        dir[2][4][3] = true;
        dir[2][4][5] = true;
        dir[3][4][2] = true;
        dir[3][4][5] = true;
        dir[3][4][6] = true;
        dir[1][5][1] = true;
        dir[1][5][4] = true;
        dir[1][5][6] = true;
        dir[0][5][2] = true;
        dir[0][5][3] = true;
        dir[0][5][4] = true;
        dir[0][6][2] = true;
        dir[0][6][3] = true;
        dir[0][6][4] = true;
        dir[2][6][1] = true;
        dir[2][6][3] = true;
        dir[2][6][5] = true;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<vector<int>> q;
        q.push({0,0});
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            vis[u[0]][u[1]] = true;
            for ( int k = 0 ; k < 4 ; ++k ) {
                int newU = u[0] + dx[k];
                int newV = u[1] + dy[k];
                if ( 0 <= newU && newU < m && 0 <= newV && newV < n && !vis[newU][newV] && dir[k][grid[u[0]][u[1]]][grid[newU][newV]]) {
                    vis[newU][newV] = true;
                    q.push({newU,newV});
                }
            }
        }
        return vis[m-1][n-1];
    }
};
