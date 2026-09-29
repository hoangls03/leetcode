const int dx[] = {0,1};
const int dy[] = {1,0};
class Solution {
public:
    bool DFS(int u, int v, vector<vector<char>>& grid, vector<vector<vector<bool>>>& vis, int countOpen) {
        int m = grid.size();
        int n = grid[0].size();
        if (countOpen < 0 || countOpen > m * n / 2)
            return false;
        if (vis[u][v][countOpen])
            return false;
        vis[u][v][countOpen] = true;
        if ( countOpen == 0 && u == m - 1 && v == n - 1 ) {
            return true;
        }
        for ( int i = 0 ; i < 2 ; ++i ) {
            int newU = u + dx[i];
            int newV = v + dy[i];
            if ( min(newU,newV) >= 0 && newU < m && newV < n ) {
                int val = 1;
                if ( grid[newU][newV] == ')' ) {
                    val = -1;
                }
                if ( countOpen + val >= 0 && countOpen + val <= m*n/2 && !vis[newU][newV][countOpen + val] ) {
                    if ( DFS(newU,newV,grid,vis,countOpen + val) ) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(m * n,false)));
        int countOpen = 1;
        if ( grid[0][0] == ')' ) countOpen = -1;
        return DFS(0,0,grid,vis,countOpen);
    }
};
