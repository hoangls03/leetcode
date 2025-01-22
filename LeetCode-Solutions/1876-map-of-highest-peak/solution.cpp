const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(m,vector<int>(n,1e9));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( isWater[i][j] == 1 ) {
                    q.push({i,j});
                    vis[i][j] = 0;
                } 
            }
        }
        
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                vector<int> v = {dx[i] + u[0],dy[i] + u[1]};
                if ( v[0] >= 0 && v[0] < m && v[1] >= 0 && v[1] < n && vis[v[0]][v[1]] > vis[u[0]][u[1]] + 1 ) {
                    vis[v[0]][v[1]] = vis[u[0]][u[1]] + 1;
                    q.push(v);
                }
            }
        }
        return vis;
    }
};
