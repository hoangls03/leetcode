class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> deg(n,0);

        for ( int i = 0 ; i < n ; ++i ) {
            deg[favorite[i]]++;
        }

        queue<int> q;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( deg[i] == 0 ) {
                q.push(i);
            }
        }

        vector<int> d(n,1);
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            d[v] = max(d[v],d[u] + 1);
            deg[v]--;
            if ( deg[v] == 0 ) {
                q.push(v);
            }
        }
        int ans = 0;
        int join = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( deg[i] != 0 ) {
                int len = 0;
                int cur = i;
                while ( deg[cur] != 0 ) {
                    deg[cur] = 0;
                    len++;
                    cur = favorite[cur];
                }
                if ( len == 2 ) {
                    join += d[i] + d[favorite[i]];
                } else {
                    ans = max(ans,len);
                }
            }
        }
        return max(ans,join);
    }
};
