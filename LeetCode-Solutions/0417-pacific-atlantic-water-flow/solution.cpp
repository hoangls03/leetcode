const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<vector<int>> q;
        vector<vector<int>> markPac(m,vector<int>(n,0));
        for ( int j = 0 ; j < n ; ++j ) {
            q.push({0,j});
            markPac[0][j] = 1;
        }
        for ( int i = 0 ; i < m ; ++i ) {
            q.push({i,0});
            markPac[i][0] = 1;
        }
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            markPac[u[0]][u[1]] = 1;
            for ( int i = 0 ; i < 4 ; ++i ) { 
                int X = u[0] + dx[i];
                int Y = u[1] + dy[i];
                if ( 0 <= X && X < m && 0 <= Y && Y < n && heights[X][Y] >= heights[u[0]][u[1]] && markPac[X][Y] == 0) {
                    q.push({X,Y});
                }
            } 
        }
        vector<vector<int>> markAtl(m,vector<int>(n,0));
        for ( int j = 0 ; j < n ; ++j ) {
            q.push({m - 1,j});
            markAtl[m - 1][j] = 1;
        }
        for ( int i = 0 ; i < m ; ++i ) {
            q.push({i,n - 1});
            markAtl[i][n - 1] = 1;
        }
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            markAtl[u[0]][u[1]] = 1;
            for ( int i = 0 ; i < 4 ; ++i ) { 
                int X = u[0] + dx[i];
                int Y = u[1] + dy[i];
                if ( 0 <= X && X < m && 0 <= Y && Y < n && heights[X][Y] >= heights[u[0]][u[1]] && markAtl[X][Y] == 0) {
                    q.push({X,Y});
                }
            } 
        }
        vector<vector<int>> ans;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( markPac[i][j] == 1 && markAtl[i][j] == 1 ) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
