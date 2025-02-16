class Solution {
public:
    int calSum( int sum, int n ) {
        int s = 0;
        int x = n;
        int m = 1;
        while ( n ) {
            s = ( n % 10 ) * m + s;
            n /= 10;
            m *= 10;
            if ( s + calSum(sum-s,n) == sum ) {
                return sum;
            }
        }
        return x;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            if (calSum(i,i*i) == i) {
                ans += i*i;
            } 
        }
        return ans;
    }
};
