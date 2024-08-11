const int oo = 1e9 + 7;
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        long long dp[2005][1005];
        memset(dp,0,sizeof(dp));
        for ( int i = 0 ; i <= nums[0] ; ++i ) {
            dp[0][i] = 1;
        }
        long long ans = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            long long sum = 0;
            int pos = nums[i-1];
            for ( int j = nums[i] ; j >= 0 ; --j ) {
                int arr1 = nums[i] - j;
                while ( nums[i-1] - pos <= arr1 && pos >= 0 && pos >= j ) {
                    sum = ( sum + dp[i-1][pos] ) % oo;
                    pos--;
                }
                dp[i][j] = ( dp[i][j] + sum ) % oo;
            }
        }
        for ( int i = 0 ; i <= nums[n-1] ; ++i ) {
            ans = ( ans + dp[n-1][i] ) % oo; 

        } 
        return ans;
    }
};
