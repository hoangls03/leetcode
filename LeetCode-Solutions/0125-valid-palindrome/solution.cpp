class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string t = "";
        for ( int i = 0 ; i < n ; ++i ) {
            if ( 'a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z' || '0' <= s[i] && s[i] <= '9' ) {
                t += tolower(s[i]);
                
            }
        }
        string ans = t;
        reverse(t.begin(),t.end());
        return (t == ans);
    }
};
