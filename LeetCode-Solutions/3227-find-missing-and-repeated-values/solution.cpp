class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mark(n*n+1,0);
        for ( auto g : grid ) {
            for ( auto i : g ) {
                mark[i]++;
            }
        }
        vector<int> ans(2,0);
        for ( int i = 1 ; i <= n*n ; ++i ) {
            if ( mark[i] > 1 ) {
                ans[0] = i;
            }
            if ( mark[i] == 0 ) {
                ans[1] = i;
            }
        }
        return ans;
    }
};
