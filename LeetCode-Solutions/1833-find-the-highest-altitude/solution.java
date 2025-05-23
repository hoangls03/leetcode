class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int sum = 0;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += gain[i];
            ans = Math.max(ans,sum);
        }
        return ans;
    }
}
