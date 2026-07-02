const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<vector<int>> q;
        q.push({0,0});
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> d(m,vector<int>(n,1e9));
        d[0][0] = grid[0][0];
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                vector<int> v = {u[0] + dx[i], u[1] + dy[i]};
                if ( 0 <= v[0] && v[0] < m && 0 <= v[1] && v[1] < n && d[v[0]][v[1]] > d[u[0]][u[1]] + grid[v[0]][v[1]]) {
                    d[v[0]][v[1]] = d[u[0]][u[1]] + grid[v[0]][v[1]];
                    q.push(v);
                }
            }
        }
        return ( d[m - 1][n - 1] < health );
    }
};
