class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long temp = start^goal;
        int ans = 0;
        while ( temp > 0 ) {
            int logtemp = log2(temp);
            temp -= ( 1 << logtemp );
            ans++;
        }
        return ans;
    }
};
