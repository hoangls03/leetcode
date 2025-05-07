const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        queue<vector<int>> q;
        q.push({0,0});
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<long long>> d(m,vector<long long>(n,1e18));
        d[0][0] = 0;
        while ( q.size() ) {
            auto u = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                vector<int> v = {u[0] + dx[i], u[1] + dy[i]};
                if ( 0 <= v[0] && v[0] < m && 0 <= v[1] && v[1] < n && d[v[0]][v[1]] > max(d[u[0]][u[1]],1LL*moveTime[v[0]][v[1]]) + 1 ) {
                    d[v[0]][v[1]] = max(d[u[0]][u[1]],1LL*moveTime[v[0]][v[1]]) + 1;
                    q.push(v);
                }
            }
        }
        return d[m-1][n-1];
    }
};
