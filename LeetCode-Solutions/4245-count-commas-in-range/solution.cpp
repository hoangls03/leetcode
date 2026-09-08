class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            int tmp = i;
            int digit = 0;
            while ( tmp ) {
                digit++;
                tmp /= 10;
            }
            digit--;
            ans += digit/3;
        }
        return ans;
    }
};
