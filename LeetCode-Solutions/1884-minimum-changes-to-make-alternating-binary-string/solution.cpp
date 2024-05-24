class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        s = " " + s;
        int ans0 = 0, ans1 = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( i & 1 ) {
                if ( s[i] == '0' ) ans1++;
                else ans0++;
            }
            else {
                if ( s[i] == '1' ) ans1++;
                else ans0++;
            }
        }
        int ans = min(ans1,ans0);
        return ans;
    }
};
