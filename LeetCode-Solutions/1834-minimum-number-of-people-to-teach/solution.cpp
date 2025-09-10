class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<vector<int>> mark(505,vector<int>(n + 1,0));
        int m = languages.size();
        for ( int i = 0 ; i < m ; ++i ) {
            for ( auto j : languages[i] ) {
                mark[i + 1][j] = 1;
            }
        }
        vector<int> dp(n + 1,0);
        set<int> needToTeach;
        for ( auto fr : friendships ) {
            bool ok = false;
            for ( int i = 1 ; i <= n ; ++i ) {
                if ( mark[fr[0]][i] + mark[fr[1]][i] == 2 ) {
                    ok = true;
                    break;
                }
            }
            if ( !ok ) {
                needToTeach.insert(fr[0]);
                needToTeach.insert(fr[1]);
            }
        }
        for ( auto i : needToTeach ) {
            for ( int j = 1 ; j <= n ; ++j ) {
                dp[j] += (mark[i][j] != 1);
            }
        }
        int ans = 500;
        for ( int i = 1 ; i <= n ; ++i ) {
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};
