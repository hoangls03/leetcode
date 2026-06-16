class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for ( auto i : s ) {
            if ( i == '#' ) {
                ans += ans;
            } else if ( i == '*' ) {
                int n = ans.size();
                if ( n == 0 ) {
                    continue;
                }
                ans = ans.substr(0,n - 1);
            } else if ( i == '%' ) {
                reverse(ans.begin(),ans.end());
            } else {
                ans += i;
            }
        }
        return ans;
    }
};
