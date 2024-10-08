class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int open = 0, close = 0;
        for ( auto i : s ) {
            if ( i == '[' ) {
                open++;
            } else if ( open > 0 ) open--;
            else {
                close++;
            }
        }
        ans = open/2 + open%2;
        return ans;
    }
};
