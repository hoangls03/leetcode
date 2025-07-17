#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            nums[i] %= k;
        }
        int dp[1005][1005];
        int mark[1005][1005];
        int ans = 0;
        for ( int i = 0 ; i < 1000 ; ++i ) {
            for ( int j = 0 ; j < 1000 ; ++j ) {
                dp[i][j] = 0;
                mark[i][j] = -1;
            }
        } 
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < k ; ++j )
                dp[j][j] += (nums[i] == j);
        }
        for ( int j = 0 ; j < k ; ++j ) {
            ans = max(ans,dp[j][j]);
        }
        for ( int i = 0 ; i < n ; ++i ) {
            int zz = nums[i];
            for ( int jj = 0 ; jj < k ; ++jj ) {
                int j = jj;
                int z = zz;
                if ( z < j ) swap(z,j);
                if ( mark[j][z] != nums[i] && j != z ) {
                    dp[j][z]++;
                    mark[j][z] = nums[i];
                }
                ans = max(ans,dp[j][z]);
            }
            
        }
        return ans;
    }
};
