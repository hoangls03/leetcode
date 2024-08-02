class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        int sum = 0;
        for ( auto i : nums ) {
            sum += i;
        }
        int local_sum = 0;
        for ( int i = 0 ; i < 2*n ; ++i ) {
            local_sum += nums[i%n];
            if ( i >= sum ) {
                local_sum -= nums[(i-sum)%n];
            }
            ans = min(ans,sum-local_sum);
        }
        return ans;
    }
};
