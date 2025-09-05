class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans = -1;
        for ( int i = 1 ; i <= 60 ; ++i ) {
            if ( num1 - 1LL*i*num2 >= 0 ) {
                long long num = num1 - 1LL*i*num2;
                int res = __builtin_popcountll(num);
                if ( res <= i && i <= num ) {
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};
