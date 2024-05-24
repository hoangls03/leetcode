class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int a[100005];
        memset(a,0,sizeof(a));
        int n = s.size();
        s = " " + s;
        t = " " + t;
        for ( int i = 1 ;  i <= n ; ++i ) {
            a[i] = a[i-1] + abs(s[i] - t[i]);
        }
        int l = 1, r = n,ans = 0;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            bool check = false;
            for ( int i = 1 ; i <= n && !check; ++i ) {
                if ( (i + mid - 1) <= n && a[i+mid-1] - a[i-1] <= maxCost ) check = true;
            }
            if ( check ) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
