class Solution {
public:
    int smallestNumber(int n, int t) {
        while ( true ) {
            int tmp = n;
            long long ans = 1;
            while ( tmp ) {
                ans = ans * (tmp % 10);
                tmp /= 10;
            }
            if ( ans % t == 0 ) {
                return n;
                break;
            }
            n++;
        }
    }
};
