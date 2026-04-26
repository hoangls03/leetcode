const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool DFS(int prevU, int prevV, int u, int v, vector<vector<char>>& grid, vector<vector<bool>>& vis ){
        int m = grid.size();
        int n = grid[0].size();
        vis[u][v] = true;
        for ( int k = 0 ; k < 4 ; ++k ) {
            int newU = u + dx[k];
            int newV = v + dy[k];
            if ( 0 <= newU && newU < m && 0 <= newV && newV < n && ( newU != prevU || newV != prevV) && grid[newU][newV] == grid[u][v] ) {
                if ( vis[newU][newV] ) {
                    return true;
                } else {
                    vis[newU][newV] = true;
                    bool ans = DFS(u,v,newU,newV,grid,vis);
                    if ( ans == true ) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        bool ans = false;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( !vis[i][j] ) {
                    bool val = DFS(i,j,i,j,grid,vis);
                    ans = ans | val;
                }
            }
        }
        return ans;
    }
};
