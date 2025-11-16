const int oo = 1e9 + 7;
class Solution {
public:
    int numSub(string s) {
        long long count1 = 0;
        long long ans = 0;
        s += '0';
        for ( auto i : s ) {
            if ( i == '1' ) {
                count1++;
            } else {
                ans += 1LL*count1*(count1 + 1)/2;
                ans %= oo;
                count1 = 0;
            }
        }
        return ans;
    }
};
