class Solution {
public:
    void DFS( int u, vector<int>& edges, vector<int>& d) {
        int v = edges[u];
        if ( v != -1 && ( d[v] == -1 || d[u] + 1 < d[v] ) ) {
            d[v] = d[u] + 1;
            DFS(v,edges,d);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d(n,-1);
        vector<int> d1(n,-1);
        d[node1] = 0;
        d1[node2] = 0;
        DFS(node1,edges,d);
        DFS(node2,edges,d1);
        int ans = 1e9;
        int res = -1;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( d[i] != -1 && d1[i] != -1 ) {
                if ( max(d[i],d1[i]) <= ans ) {
                    if ( max(d[i],d1[i]) == ans ) {
                        res = min(res,i);
                    } else {
                        res = i;
                    }
                    ans = max(d[i],d1[i]);
                }
            }
        }
        return res;
    }
};
