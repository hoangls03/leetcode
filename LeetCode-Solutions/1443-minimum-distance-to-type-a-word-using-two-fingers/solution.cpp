#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    map<char,ii> mark;
    int calPoint(char A, char B) {
        return abs(mark[A].fi - mark[B].fi) + abs(mark[A].se - mark[B].se);
    }
    int minimumDistance(string word) {
        char ch = 'A';
        
        for ( int i = 0 ; i < 5 ; ++i ) {
            for ( int j = 0 ; j < 6 ; ++j ) {
                mark[ch] = {i,j};
                ch += 1;
                
            }
        }
        int n = word.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,1e9));
        dp[1][0] = 0;
        int ans = 1e9;
        for ( int i = 2 ; i <= n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                for ( int z = 0 ; z < i ; ++z ) {

                    if ( j + 1 == i || z + 1 == i ) {
                        int tmp = (j == 0) ? 0 : calPoint(word[i-1],word[j - 1]);
                        int tmp2 = (z == 0) ? 0 : calPoint(word[i-1],word[z - 1]);

                        
                        dp[i][z] = min(dp[i][z], dp[j][z] + tmp);
                        dp[j][i] = min(dp[j][i], dp[j][z] + tmp2);
                        if ( i == n ) {
                            ans = min({ans,dp[i][z],dp[j][i]});
                        }
                    }
                }
            }
        }
        return ans;

    }
};
