class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int max_count = 0;
        vector<int> ans;
        vector<int> dp(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                if ( nums[i] % nums[j] == 0 ) {
                    //cout<<i<<" "<<j<<'\n';
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            max_count = max(max_count,dp[i]);
        }
        //cout<<max_count<<'\n';
        int num = -1;
        int count = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            //cout<<dp[i]<<" "<<num<<" "<<nums[i]<<" "<<count<<'\n';
            if ( num != -1 && num % nums[i] == 0 && dp[i] == count ) {
                num = nums[i];
                count = dp[i] - 1;
                ans.push_back(num);
            }
            if ( num == -1 && dp[i] == max_count ) {
                num = nums[i];
                count = dp[i] - 1;
                ans.push_back(num);
            }
        }
        return ans;
    }
};
