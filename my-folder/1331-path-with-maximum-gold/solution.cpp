#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    int DFS( int u, int v, int m, int n, vector<vector<int>>& grid) {
        if ( u < 0 || u >= m || v < 0 || v >= n || grid[u][v] == 0 ) return 0;
        int curr = grid[u][v];
        grid[u][v] = 0;
        int temp = curr;

        for ( int i = 0 ; i < 4 ; ++i ) {
            int u_new = u + dx[i];
            int v_new = v + dy[i];
            temp = max(temp,curr + DFS(u_new,v_new,m,n,grid));
        }
        grid[u][v] = curr;
        return temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] !=0 ) {
                    ans = max(ans,DFS(i,j,m,n,grid));
                }
            }
        }
        return ans;
    }
};
