#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int q = queries.size();
        vector<int> saveQueries = queries;
        sort(queries.begin(),queries.end());
        priority_queue<iii,vector<iii>,greater<iii>> pq;
        int pos = 0;
        pq.push({grid[0][0],{0,0}});
        int ans = 0;
        vector<int> mark(1e6 + 1);
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[0][0] = 1;
        while ( pq.size() ) {
            auto u = pq.top();
            vis[u.se.fi][u.se.se] = 1;
            pq.pop();
            while ( pos < q && u.fi >= queries[pos] ) {
                mark[queries[pos]] = ans;
                pos++;
            }
            ans++;
            for ( int i = 0 ; i < 4 ; ++i ) {
                ii v = {u.se.fi + dx[i],u.se.se + dy[i]};
                if ( 0 <= v.fi && v.fi < m && 0 <= v.se && v.se < n && vis[v.fi][v.se] == 0 ) {
                    vis[v.fi][v.se] = 1;
                    pq.push({grid[v.fi][v.se],{v.fi,v.se}});
                }
            }
        }
        
        while ( pos < q ) {
            mark[queries[pos]] = ans;
            pos++;
        }
        
        vector<int> res;
        
        for ( auto i : saveQueries ) {
            res.push_back(mark[i]);
        }
        
        return res;
    }
};
