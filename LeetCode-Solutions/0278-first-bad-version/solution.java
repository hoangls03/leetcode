/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        long l = 1;
        long r = n;
        int ans = -1;
        while ( l <= r ) {
            long sum = l + r;
            sum /= 2;
            int mid = (int)sum;
            if ( !isBadVersion(mid) ) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
}
