class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(200*100+1,false);
        dp[0] = true;
        int sum = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            for ( int j = n*100 ; j >= nums[i] ; --j ) {
                dp[j] = dp[j] | dp[j-nums[i]]; 
            }
        }
        if ( sum & 1 ) return false;
        return dp[sum/2];
    }
};
