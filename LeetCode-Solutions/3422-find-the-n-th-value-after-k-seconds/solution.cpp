const int oo = 1e9 + 7;
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int a[1005],b[1005];
        for ( int i = 0 ; i < n ; ++i ) {
            a[i] = 1;
        }
        while ( k > 0 ) {
            
            for ( int i = 0 ;i < n ; ++i ) {
                b[i] = a[i];
            }
            long long sum = 1;
            for ( int i = 1 ; i < n ; ++i ) {
                sum = (sum + b[i])%oo;
                a[i] = sum;
            }
            k--;
        }
        return a[n-1];
    }
};
