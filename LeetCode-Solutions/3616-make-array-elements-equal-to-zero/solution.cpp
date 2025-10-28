class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1,0);
        sum[0] = nums[0];
        for ( int i = 1 ; i < n ; ++i ) {
            sum[i] = sum[i-1] + nums[i];
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( nums[i] == 0 ) {
                if ( sum[n - 1] - sum[i] == sum[i] ) {
                    ans += 2;
                } else if ( abs(sum[n-1] - 2*sum[i]) == 1 ) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
