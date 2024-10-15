class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int num1 = 0;
        for ( auto i : s ) {
            num1 += ( i == '1' );
            if ( i == '0' ) ans += num1;
        }
        return ans;
    }
};
