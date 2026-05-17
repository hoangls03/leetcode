class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<int> vis(n,0);
        while ( q.size() ) {
            int u = q.front();
            vis[u] = 1;
            q.pop();
            int v = u + arr[u];
            if ( 0 <= v && v < n && vis[v] == 0 ) {
                vis[v] = 1;
                q.push(v);
            }
            v = u - arr[u];
            if ( 0 <= v && v < n && vis[v] == 0 ) {
                vis[v] = 1;
                q.push(v);
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( vis[i] == 1 && arr[i] == 0 ) {
                return true;
            }
        }
        return false;
    }
};
