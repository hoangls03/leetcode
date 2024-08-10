#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    void BFS(int x, int y, vector<vector<int>>& a, int n ) {
        queue<ii> q;
        q.push({x,y});
        while ( q.size() ) {
            ii u = q.front();
            q.pop();
            a[u.fi][u.se] = 1;
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.fi+dx[i],u.se+dy[i]};
                if ( 0 <= min(v.fi,v.se) && max(v.fi,v.se) < n && a[v.fi][v.se] == 0 ) {
                    q.push(v);
                    a[v.fi][v.se] = 1;
                }
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> a(3*n,vector<int>(3*n,0));
        for ( int i = 0 ; i < n ; ++i ) {
            string s = grid[i];
            for ( int j = 0 ; j < s.size() ; ++j ) {
                if ( s[j] == '\\' ) {
                    a[i*3][j*3] = 1;
                    a[i*3+1][j*3+1] = 1;
                    a[i*3+2][j*3+2] = 1;
                } 
                if ( s[j] == '/' ) {
                    a[i*3][j*3+2] = 1;
                    a[i*3+1][j*3 + 1] = 1;
                    a[i*3+2][j*3] = 1;
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < 3*n ; ++i ) {
            for ( int j = 0 ; j < 3*n ; ++j ) {
                if ( a[i][j] == 0 ) {
                    BFS(i,j,a,3*n);
                    ans++;
                }
            }
        }
        return ans;
    }
};
