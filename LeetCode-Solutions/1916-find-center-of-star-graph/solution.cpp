class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> mark(100005,0);
        for ( int i = 0 ; i < n ; ++i ) {
            int u = edges[i][0];
            int v = edges[i][1];
            mark[u]++;
            mark[v]++;
        }
        int count = 0;
        for ( int i = 0 ; i <= 100000 ; ++i ) {
            count += (mark[i] != 0);
        }
        for ( int i = 0 ; i <= 100000 ; ++i ) {
            if ( mark[i] == count - 1) {
                return i;
            }
        }
        return -1;
    }
};
