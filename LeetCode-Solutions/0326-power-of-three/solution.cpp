class Solution {
public:
    bool isPowerOfThree(int n) {
        long long s = 1;
        for ( int i = 1 ; i <= 20 ; ++i ) {
            if ( s == n ) return true;
            s = s * 3;
        }
        return false;
    }
};
