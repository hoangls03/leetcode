class Solution {
public:
    void DFS( int u, vector<vector<int>>& g, vector<int>& d ) {
        for ( auto v : g[u] ) {
            if ( d[v] > d[u] ) {
                d[v] = d[u];
                DFS(v,g,d);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> g('z' + 1);
        int n = s1.size();
        for ( int i = 0 ; i < n ; ++i ) {
            g[s1[i]].push_back(s2[i]);
            g[s2[i]].push_back(s1[i]);
        }
        vector<int> d('z' + 1,1e9);
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( d[i] == 1e9 ) {
                d[i] = i;
                DFS(i,g,d);
            }
        }
        string ans = "";
        for ( auto i : baseStr ) {
            ans += (char)d[i];
        }
        return ans;
    }
};
