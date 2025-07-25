class Solution {
public:
    void DFS( int par, int u, vector<vector<int>>& g, vector<int>&vals, vector<int>& mark, int val) {
        mark[u] = val;
        for ( auto v : g[u] ) {
            if ( par != v ) {
                mark[v] = 1;
                DFS(u,v,g,vals,mark,val);
                vals[u] ^= vals[v];
            } 
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for ( auto e : edges ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 1e9;
        for ( int i = 0 ; i < n - 1; ++i ) {
            vector<vector<int>> g1(n);
            vector<int> vals(n,0);
            for ( int j = 0 ; j < n ; ++j ) {
                vals[j] = nums[j];
            }
            for ( int j = 0 ; j < n - 1 ; ++j ) {
                if ( i != j ) {
                    g1[edges[j][0]].push_back(edges[j][1]);
                    g1[edges[j][1]].push_back(edges[j][0]);
                }
            }
            vector<int> mark(n,0);
            int pos = 0;
            for ( int j = 0 ; j < n ; ++j ) {
                if ( mark[j] == 0 ) {
                    pos = j;
                    DFS(j,j,g1,vals,mark,pos + 1);
                }

            }
            int valR1 = vals[0];
            int valR2 = vals[pos];
            for ( int j = 0 ; j < n ; ++j ) {
                if ( j != 0 && j != pos ) {
                    int valR3;
                    vector<int> save;
                    int valR6;
                    if ( mark[j] == 1 ) {
                        valR3 = valR1^vals[j];
                        valR6 = valR2;
                    } else {
                        valR3 = valR2^vals[j];
                        valR6 = valR1;
                    }
                    int valR4 = min({vals[j],valR6,valR3});
                    int valR5 = max({vals[j],valR6,valR3});
                    ans = min(ans,valR5 - valR4);
                }
            }
        }
        return ans;
    }
};
