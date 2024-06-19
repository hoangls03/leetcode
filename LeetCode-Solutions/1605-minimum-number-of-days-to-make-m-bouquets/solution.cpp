class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ( n < 1LL*m*k ) return -1;
        int l = 1;
        int r = 1e9;
        int ans = -1;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            int count = 0, temp = 0;
            for ( int i = 0 ; i < n ; ++i ) {
                if ( mid >= bloomDay[i] ) {
                    temp++;
                    if ( temp == k ) {
                        count++;
                        temp = 0;
                    }
                } else {
                    temp = 0;
                }
            }
            if ( count >= m ) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
