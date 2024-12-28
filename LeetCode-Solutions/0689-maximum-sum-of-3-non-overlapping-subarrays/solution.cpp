#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        vector<int> sum(n,0);
        reverse(nums.begin(),nums.end());
        sum[0] = nums[0];
        for ( int i = 1 ; i < n ; ++i ) {
            sum[i] = sum[i-1] + nums[i];
        }
        for ( int i = k - 1 ; i < n ; ++i ) {
            dp[i][0] = sum[i] - sum[i-k+1] + nums[i-k+1];
            if ( i > 0 ) dp[i][0] = max(dp[i-1][0],dp[i][0]);
            if ( i >= 2*k - 1 ) {
                dp[i][1] = max(dp[i-1][1],dp[i-k][0] + sum[i] - sum[i-k]);
            }
            if ( i >= 3*k - 1 ) {
                dp[i][2] = max(dp[i-1][2],dp[i-k][1] + sum[i] - sum[i-k]);
            }
        }
        vector<int> ans;
        int pos = n - 1;
        int round = 2;
        int val = dp[n-1][2];
        while ( round > -1 ) {
            for ( int i = pos ; i >= 0 ; --i ) {
                if ( round > 0 ) {
                    if ( dp[i-k][round-1] + sum[i] - sum[i-k] == val ) {
                        ans.push_back(n-1-i);
                        val -= sum[i] - sum[i-k];
                        pos = i - k;
                        break;
                    }
                } else {
                    if ( sum[i] - sum[i-k+1] + nums[i-k+1] == val) {
                        ans.push_back(n-1-i);
                        break;
                    }
                }
            }
            round--;
        }
        return ans;
    }
};
