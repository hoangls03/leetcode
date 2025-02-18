class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n = nums.length;
        int localMax = nums[0];
        long ans[] = new long[n];
        ans[0] = localMax + nums[0];
        for ( int i = 1 ; i < n ; ++i ) {
            localMax = Math.max(localMax,nums[i]);
            ans[i] = ans[i-1] + localMax + nums[i];
        }
        return ans;
    }
}
