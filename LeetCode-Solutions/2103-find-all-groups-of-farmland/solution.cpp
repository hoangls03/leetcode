#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool check( int u, int v, int m , int n ) {
        if ( 0 <= u && u < m && 0 <= v && v < n ) return true;
        return false;
    }
    void BFS( int u, int v, int m, int n, vector<vector<int>>& land, vector<vector<int>>& ans ) {
        land[u][v] = 0;
        vector<int> temp;
        int x = u;
        int y = v;
        temp.push_back(x);
        temp.push_back(y);
        queue<ii> q;
        q.push({u,v});
        while ( q.size() ) {
            u = q.front().fi;
            v = q.front().se;
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                int u_new = u + dx[i];
                int v_new = v + dy[i];
                if ( check(u_new,v_new,m,n) && land[u_new][v_new] == 1 ) {
                    x = max(x,u_new);
                    y = max(y,v_new);
                    land[u_new][v_new] = 0;
                    q.push({u_new,v_new});
                }
            }
        }
        temp.push_back(x);
        temp.push_back(y);
        ans.push_back(temp);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( land[i][j] == 1 ) {
                    BFS(i,j,m,n,land,ans);
                }
            }
        }
        return ans;
    }
};
