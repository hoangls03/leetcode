class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for ( int j = 0 ; j < m ; ++j ) {
            int m = strs.size();
            bool ok = true;
            for ( int i = 1 ; i < n ; ++i ) {
                if ( strs[i][j] < strs[i-1][j] ) {
                    ok = false;
                }
            }
            ans += !ok;
        }
        return ans;
    }
};
