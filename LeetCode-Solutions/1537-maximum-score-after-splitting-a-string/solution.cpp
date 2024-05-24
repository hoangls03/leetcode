class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        s = " " + s;
        int sum1 = 0,dem0 = 0,dem1 = 0,ans = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( s[i] == '1' ) sum1++;
        }
        for ( int i = 1 ; i < n ; ++i ) {
            if ( s[i] == '0' ) dem0++;
            else dem1++;
            ans = max(ans,sum1 - dem1 + dem0);
        }
        return ans;
    }
};
