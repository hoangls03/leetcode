const int oo = 1e9 + 7;
class Solution {
public:
    bool check(char ch) {
        if ( '1' <= ch && ch <= '9' ) return true;
        return false;
    }
    bool checkLast(char ch) {
        if ( ch == 'S' ) return true;
        return false;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1e9));
        vector<vector<long long>> f(m,vector<long long>(n,0));
        dp[0][0] = 0;
        f[0][0] = 1;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( ( i != 0 || j != 0 ) && !check(board[i][j]) ) continue;
                if ( i + 1 < m ) {
                    if ( check(board[i+1][j]) ) {
                        int val = dp[i][j] + board[i+1][j] - '0';
                        if ( val >= dp[i+1][j] ) {
                            if (val == dp[i+1][j] ) {
                                f[i+1][j] += f[i][j];
                            } else {
                                f[i+1][j] = f[i][j];
                            }
                            f[i+1][j] %= oo;
                            dp[i+1][j] = val;
                        }
                    }
                    if ( checkLast(board[i+1][j]) ) {
                        int val = dp[i][j];
                        if ( val >= dp[i+1][j] ) {
                            if (val == dp[i+1][j] ) {
                                f[i+1][j] += f[i][j];
                            } else {
                                f[i+1][j] = f[i][j];
                            }
                            f[i+1][j] %= oo;
                            dp[i+1][j] = val;
                        }
                    }
                }
                if ( j + 1 < n ) {
                    if ( check(board[i][j+1]) ) {
                        int val = dp[i][j] + board[i][j+1] - '0';
                        if ( val >= dp[i][j+1] ) {
                            if (val == dp[i][j+1] ) {
                                f[i][j + 1] += f[i][j];
                            } else {
                                f[i][j + 1] = f[i][j];
                            }
                            f[i][j+1] %= oo;
                            dp[i][j + 1] = val;
                        }
                    }
                    if ( checkLast(board[i][j + 1]) ) {
                        int val = dp[i][j];
                        if ( val >= dp[i][j+1] ) {
                            if (val == dp[i][j + 1] ) {
                                f[i][j + 1] += f[i][j];
                            } else {
                                f[i][j + 1] = f[i][j];
                            }
                            f[i][j+1] %= oo;
                            dp[i][j + 1] = val;
                        }
                    }
                }
                if ( i + 1 < m && j + 1 < n ) {
                    if ( check(board[i+1][j+1]) ) {
                        int val = dp[i][j] + board[i+1][j+1] - '0';
                        if ( val >= dp[i+1][j+1] ) {
                            if (val == dp[i+1][j+1] ) {
                                f[i+1][j+1] += f[i][j];
                            } else {
                                f[i+1][j+1] = f[i][j];
                            }
                            f[i+1][j+1] %= oo;
                            dp[i+1][j+1] = val;
                        }
                    }
                    if ( checkLast(board[i+1][j+1]) ) {
                        int val = dp[i][j];
                        if ( val >= dp[i+1][j+1] ) {
                            if (val == dp[i+1][j+1] ) {
                                f[i+1][j+1] += f[i][j];
                            } else {
                                f[i+1][j+1] = f[i][j];
                            }
                            f[i+1][j+1] %= oo;
                            dp[i+1][j+1] = val;
                        }
                    }
                }
            }
        }
        int val = f[m-1][n-1]%oo;
        if ( val == 0 ) {
            return {0,0};
        }
        return {dp[m-1][n-1],val};
    }
};
