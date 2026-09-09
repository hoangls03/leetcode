class Solution {
public:
    long long countCommas(long long n) {
        long long cur = 1;
        long long ans = 0;
        int comma = 0;
        while ( cur*1000 <= n ) {
            ans += comma * (cur*1000 - cur);
            cur *= 1000;
            comma++;
        }
        ans += comma*(n - cur + 1);
        return ans;
    }
};
