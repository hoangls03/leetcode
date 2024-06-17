class Solution {
public:
    bool judgeSquareSum(int c) {
        for ( long long i = 0 ; i*i <= c ; ++i ) {
            int b = c-i*i;
            int a = sqrt(b);
            if ( a*a == b ) return true;
        }
        return false;
    }
};
