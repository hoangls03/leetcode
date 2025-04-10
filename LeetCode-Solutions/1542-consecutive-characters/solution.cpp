class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int ans = 1;
        int sum = 1;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( s[i] != s[i-1] ) {
                sum = 0;
            }
            sum++;
            ans = max(ans,sum);
        }
        return ans;
    }
};
