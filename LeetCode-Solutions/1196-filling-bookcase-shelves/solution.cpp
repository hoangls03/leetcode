#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n,1e9);
        dp[0] = books[0][1];
        for ( int i = 1 ; i < n ; ++i ) {
            int width = 0;
            int height = 0;
            for ( int j = i ; j >= 0 ; --j ) {
                width += books[j][0];
                height = max(height,books[j][1]);
                if ( width > shelfWidth ) break;
                int pre_height = (j == 0) ? 0 : dp[j-1];
                dp[i] = min(dp[i],pre_height + height);
            }
            cout<<dp[i]<<'\n';
        }
        return dp[n-1];
    }
};
