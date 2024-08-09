class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int check[20];
        int ans = 0;
        for ( int i = 0 ; i < 20 ; ++i )
            check[i] = 1;
        for ( int i = 0 ; i <= m - 3 ; ++i ) {
            for ( int j = 0 ; j <= n - 3 ; ++j ) {
                for ( int k = 1 ; k <= 9 ; ++k ) {
                    check[k] = 0;
                }
                bool ok = true;
                int sum = 0;
                for ( int u = i ; u < i + 3 ; ++u ) {
                    int local_sum = 0;
                    for ( int v = j ; v < j + 3 ; ++v ) {
                        if ( check[grid[u][v]] > 0  ) {
                            ok = false;
                        }
                        check[grid[u][v]]++;
                        local_sum += grid[u][v];
                    }
                    if ( u == i ) sum = local_sum;
                    if ( local_sum != sum ) ok = false;
                }
                for ( int v = j ; v < j + 3 ; ++v ) {
                    int local_sum = 0;
                    for ( int u = i ; u < i + 3 ; ++u ) { 
                        local_sum += grid[u][v];
                    }
                    if ( local_sum != sum ) ok = false;
                }
                int dio = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int counter_dio = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
                if ( dio != sum || counter_dio != sum ) ok = false;
                ans += ok;
            }
        }
        return ans;
    }
};
