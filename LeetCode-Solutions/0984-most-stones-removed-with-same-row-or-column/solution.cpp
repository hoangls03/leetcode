#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    void BFS( int u, vector<int>& mark, vector<vector<int>>& g, int& count ) {
        queue<int> q;
        q.push(u);
        mark[u] = 0;
        while ( q.size() ) {
            u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( mark[v] == 1 ) {
                    count++;
                    mark[v] = 0;
                    q.push(v);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> mark(n,1);
        vector<vector<int>> g(n);
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                if ( stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1] ) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] == 1 ) {
                int count = 0;
                BFS(i,mark,g,count);
                ans += count;
            }
        }
        return ans;
    }
};
