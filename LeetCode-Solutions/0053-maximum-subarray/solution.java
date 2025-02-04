class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int sum = 0, localMin = 0,ans = nums[0];
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            ans = Math.max(ans,sum - localMin);
            localMin = Math.min(localMin,sum);
        }
        return ans;
    }
}
