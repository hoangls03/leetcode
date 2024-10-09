class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0,ans = 0;
        for ( auto i : s ) {
            if ( i == ')' ) {
                if ( open == 0 ) ans++;
                else open--;
            } else {
                open++;
            }
        }
        ans += open;
        return ans;
    }
};
