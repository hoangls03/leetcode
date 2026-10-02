class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n = n*2;
        for ( int i = 1 ; i < (1 << n) ; ++i ) {
            string s = "";
            for ( int j = 0 ; j < n ; ++j ) {
                if ( (i >> j) & 1 ) {
                    s += '(';
                } else {
                    s += ')';
                }
            }
            bool ok = true;
            int countOpen = 0;
            for ( int j = 0 ; j < n ; ++j ) {
                if ( s[j] == '(' ) {
                    countOpen++;
                } else {
                    countOpen--;
                }
                if ( countOpen < 0 ) {
                    ok = false;
                    break;
                }
            }
            if ( countOpen != 0 ) {
                ok = false;
            }
            
            if ( ok ) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
