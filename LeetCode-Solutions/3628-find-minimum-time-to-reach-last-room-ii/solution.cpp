const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<long long>> d(m,vector<long long>(n,1e9 + 2*m*n + 1));
        d[0][0] = 0;
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        pq.push({d[0][0],0,0,0});
        while ( pq.size() ) {
            auto u = pq.top();
            pq.pop();
            for ( int i = 0 ; i < 4 ; ++i ) {
                vector<long long> v = {u[1] + dx[i], u[2] + dy[i]};
                if ( !(0 <= v[0] && v[0] < m && 0 <= v[1] && v[1] < n) ) continue;
                if ( d[v[0]][v[1]] > max(d[u[1]][u[2]],1LL*moveTime[v[0]][v[1]]) + 1 + u[3]) {
                    d[v[0]][v[1]] = max(d[u[1]][u[2]],1LL*moveTime[v[0]][v[1]]) + 1 + u[3];
                    v = {d[v[0]][v[1]],v[0],v[1],1 - u[3]};
                    pq.push(v);
                }
            }
        }
        return d[m-1][n-1];
    }
};
