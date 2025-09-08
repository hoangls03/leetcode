class Solution {
public:
    bool checkZero( int n ) {
        while ( n > 0 ) {
            if ( n % 10 == 0 ) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( checkZero(i) && checkZero(n - i) ) {
                return {i,n-i};
            }
        }
        return {};
    }
};
