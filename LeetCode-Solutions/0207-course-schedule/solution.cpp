class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> outDegree(numCourses,0);
        vector<vector<int>> g(numCourses);
        for ( auto e : prerequisites ) {
            outDegree[e[0]]++;
            g[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for ( int i = 0 ; i < numCourses ; ++i ) {
            if ( outDegree[i] == 0 ) {
                q.push(i);
            }
        }
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                outDegree[v]--;
                if ( outDegree[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        for ( int i = 0 ; i < numCourses ; ++i ) {
            if ( outDegree[i] != 0 ) {
                return false;
            }
        }
        return true;
    }
};
