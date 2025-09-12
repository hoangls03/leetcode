class Solution {
public:
    bool doesAliceWin(string s) {
        string vowel = "aeiou";
        int res = 0;
        for ( auto i : s ) {
            for ( auto j : vowel ) {
                if ( j == i ) {
                    res++;
                    break;
                }
            }
        }
        if ( res == 0 ) return false;
        return true;
    }
};
