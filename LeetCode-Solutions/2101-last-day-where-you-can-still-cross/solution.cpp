const int dx[] = {-1,0,1,-1,1,-1,0,1};
const int dy[] = {1,1,1,0,0,-1,-1,-1};
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        vector<vector<int>> grid(row + 2,vector<int>(col + 2,0));
        while ( l <= r ) {
            int mid = (l + r) >> 1;
            queue<vector<int>> q;
            for ( int i = 0 ; i <= mid ; ++i ) {
                int x = cells[i][0];
                int y = cells[i][1];
                grid[x][y] = 1;
                if ( y == 1 ) {
                    q.push(cells[i]);
                }
            }
            bool ok = false;
            vector<vector<int>> vis(row + 2,vector<int>(col + 2,0));
            while ( q.size() ) {
                auto u = q.front();
                if ( u[1] == col ) {
                    ok = true;
                }
                vis[u[0]][u[1]] = 1;
                q.pop();
                for ( int k = 0 ; k < 8 ; ++k ) {
                    int newX = u[0] + dx[k];
                    int newY = u[1] + dy[k];
                    if ( 1 <= newX && newX <= row && 1 <= newY && newY <= col && grid[newX][newY] == 1 && vis[newX][newY] == 0 ) {
                        vector<int> v = {newX,newY};
                        vis[newX][newY] = 1;
                        q.push(v);
                    }
                }
            }
            
            if ( !ok ) {
                ans = max(ans,mid + 1);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            for ( int i = 0 ; i <= mid ; ++i ) {
                int x = cells[i][0];
                int y = cells[i][1];
                grid[x][y] = 0;
            }
        }
        return ans;
    }
};
