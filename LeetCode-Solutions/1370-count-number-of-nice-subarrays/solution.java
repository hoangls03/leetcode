class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int sum = 0;
        int[] count = new int [n + 1];
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            nums[i] = nums[i]%2;
        }
        count[0] = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            count[sum]++;
            if ( sum >= k ) {
                ans += count[sum-k];
            }
            
        }
        return ans;
    }
}
