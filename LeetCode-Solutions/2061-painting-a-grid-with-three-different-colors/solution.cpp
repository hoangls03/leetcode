const int oo = 1e9 + 7;
class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<vector<int>> colSet;
        colSet.push_back({0});
        colSet.push_back({1});
        colSet.push_back({2});
        
        for ( int i = 1 ; i < m ; ++i ) {
            vector<vector<int>> clone;
            for ( auto col : colSet ) {
                vector<int> tmp = col;
                for ( int j = 0 ; j <= 2 ; ++j ) {
                    if ( j != col[col.size() - 1] ) {
                        tmp.push_back(j);
                        clone.push_back(tmp);
                        tmp = col;
                    }
                }

            }
            colSet = clone;
        }
        int comb = colSet.size();
        vector<vector<int>> dp(n,vector<int>(comb,0));
        vector<vector<int>> mark(comb,vector<int>(comb,0));
        for ( int i = 0 ; i < comb ; ++i ) {
            for ( int j = 0 ; j < comb ; ++j ) {
                bool check = true;
                for ( int z = 0 ; z < m && check; ++z ) {
                    if ( colSet[i][z] == colSet[j][z] ) {
                        check = false;
                    }
                }
                mark[i][j] = check;
            }
        }

        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < comb ; ++j ) {
                if ( i == 0 ) {
                    dp[i][j] = 1;
                } else {
                    for( int k = 0 ; k < comb ; ++k ) {
                        if ( mark[j][k] == 1 ) {
                            dp[i][j] = (1LL*dp[i][j] + dp[i-1][k])%oo;
                        }
                    }
                }
                if ( i == n - 1 ) ans = (1LL*ans + dp[i][j])%oo;
            }
        }
        return ans;
    }
};
