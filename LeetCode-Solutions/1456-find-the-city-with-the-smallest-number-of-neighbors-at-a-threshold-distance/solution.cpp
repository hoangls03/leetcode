class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(100,vector<int>(100,1e9));
        for ( auto i : edges ) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            d[u][v] = w;
            d[v][u] = w;
        }
        for ( int k = 0 ; k < n ; ++k ) {
            for ( int u = 0 ; u < n ; ++u ) {
                for ( int v = 0 ; v < n ; ++v ) {
                    if ( d[u][v] > d[u][k] + d[k][v] ) {
                        d[u][v] = d[u][k] + d[k][v];
                    }
                }
            }
        }
        int count = 1e9;
        int local_count =0 ;
        int ans = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            local_count = 0;
            for ( int j = 0 ; j < n ; ++j ) {
                if ( i != j && d[i][j] <= distanceThreshold ) {
                    local_count++;
                } 
            }
            if ( local_count < count ) {
                ans = i;
                count = local_count;
            }
        }
        return ans;
    }
};
