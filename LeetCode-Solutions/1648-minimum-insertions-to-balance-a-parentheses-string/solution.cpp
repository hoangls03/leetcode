class Solution {
public:
    int minInsertions(string s) {
        int countParent = 0;
        int ans = 0;
        for ( auto i : s ) {
            if ( i == '(' ) {
                if ( countParent & 1 ) {
                    countParent--;
                    ans++;
                }
                countParent += 2;
            } else {
                countParent--;
            }
            if ( countParent < 0 ) {
                countParent += 2;
                ans++;
            }
        }
        if ( countParent > 0 ) {
            ans += countParent;
        } else {
            ans += (abs(countParent) + 1)/2;
        }
        return ans;
    }
};
