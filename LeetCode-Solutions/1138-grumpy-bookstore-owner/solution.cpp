class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int temp = 0;
        int n = customers.size();
        vector<int> r(n+1,0),l(n+1,0),sum(n+1,0);
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            r[i] = r[i+1];
            (grumpy[i] == 0) ? r[i] += customers[i] : 0;
        }
        sum[0] = customers[0];
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i > 0 ) {
                l[i] = l[i-1];
                sum[i] = sum[i-1] + customers[i];
            }
            (grumpy[i] == 0) ? l[i] += customers[i] : 0;

        }
        ans = r[minutes] + sum[minutes-1];
        for ( int i = minutes ; i < n ; ++i ) {
            ans = max(ans,r[i+1]+l[i-minutes]+sum[i]-sum[i-minutes]);
        }
        return ans;
    }
};
