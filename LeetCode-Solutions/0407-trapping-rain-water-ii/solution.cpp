const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        auto cmp = [&](const vector<int>& a, vector<int>& b ) {
            return a[0] >= b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( i == 0 || i == m - 1 || j == 0 || j == n - 1 ) {
                    vis[i][j] = 1;
                    pq.push({heightMap[i][j],i,j});
                }
            }
        }

        while ( pq.size() ) {
            auto u = pq.top();
            pq.pop();

            for ( int i = 0 ; i < 4 ; ++i ) {
                int x = u[1] + dx[i];
                int y = u[2] + dy[i];
                if ( 0 <= x && x < m && 0 <= y && y < n && vis[x][y] == 0 ) {
                    vis[x][y] = 1;
                    if ( heightMap[x][y] < u[0] ) {
                        ans += u[0] - heightMap[x][y];
                    }
                    pq.push({max(u[0],heightMap[x][y]),x,y});
                }
            }
        }
        return ans;
    }
};
