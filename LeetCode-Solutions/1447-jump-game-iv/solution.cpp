class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> mark;
        vector<int> vis(n,n + 1);
        for ( int i = 0 ; i < n ; ++i ) {
            mark[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vis[0] = 0;
        while(q.size()) {
            int u = q.front();
            q.pop();
            int v = u + 1;
            if ( 0 <= v && v < n && vis[v] > vis[u] + 1 ) {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
            v = u - 1;
            if ( 0 <= v && v < n && vis[v] > vis[u] + 1 ) {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
            for ( auto i : mark[arr[u]] ) {
                if ( vis[i] > vis[u] + 1) {
                    vis[i] = vis[u] + 1;
                    q.push(i);
                }
            }
            mark[arr[u]].clear();
        }
        return vis[n-1];
    }
};
