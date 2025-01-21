class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> suffix(n + 1,0);
        suffix[n-1] = grid[0][n-1];
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            suffix[i] = suffix[i+1] + grid[0][i];
        }
        long long sum = 0;
        long long ans = 1e18;
        for ( int i = 0 ; i < n ; ++i ) {
            long long temp = max(sum,suffix[i+1]);
            ans = min(ans,temp);
            sum += grid[1][i];
        }
        return ans;
    }
};
