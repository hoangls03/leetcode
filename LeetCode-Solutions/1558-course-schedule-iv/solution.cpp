class Solution {
public:
    void BFS( int root, vector<vector<bool>>& d, vector<vector<int>>& g) {
        queue<int> q;
        d[root][root] = true;
        q.push(root);
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( !d[root][v] ) {
                    d[root][v] = true;
                    q.push(v);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> d(numCourses,vector<bool>(numCourses,0));
        int n = prerequisites.size();
        vector<vector<int>> g(numCourses);
        for ( auto u : prerequisites ) {
            g[u[0]].push_back(u[1]);
        }
        for ( int i = 0 ; i < numCourses ; ++i ) {
            BFS(i,d,g);
        }
        vector<bool> ans;
        for ( auto q : queries ) {
            ans.push_back(d[q[0]][q[1]]);
        }
        return ans;
    }
};
