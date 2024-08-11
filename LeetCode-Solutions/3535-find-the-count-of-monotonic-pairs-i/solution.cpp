const int oo = 1e9 + 7;
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        long long dp[2005][55];
        memset(dp,0,sizeof(dp));
        for ( int i = 0 ; i <= nums[0] ; ++i ) {
            dp[0][i] = 1;
        }
        long long ans = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            for ( int j = 0 ; j <= nums[i] ; ++j ) {
                int arr1 = nums[i] - j;
                for ( int k = j ; k <= nums[i-1] ; ++k ) {
                    if ( arr1 >= nums[i-1] - k ) {
                        dp[i][j] = (dp[i][j] + dp[i-1][k])%oo;
                    }
                }
                
            }

        }
        for ( int i = 0 ; i <= nums[n-1] ; ++i ) {
            ans = ( ans + dp[n-1][i] ) % oo; 

        } 
        return ans;
    }
};
