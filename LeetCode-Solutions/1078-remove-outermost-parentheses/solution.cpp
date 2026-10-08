class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<int> st;
        int countParent = 0;
        for ( auto i : s ) {
            if ( i == '(' ) {
                if ( countParent != 0 ) {
                    ans += '(';
                }
                countParent++;
            } else {
                countParent--;
                if ( countParent != 0 ) {
                    ans += ')';
                }
            }
        }
        return ans;
    }
};
