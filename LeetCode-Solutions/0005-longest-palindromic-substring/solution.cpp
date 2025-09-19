class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int start = n + 1;
        int end = 0;
        int maxLen = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int len = 0 ; len < n ; ++len ) {
                if ( i + len > n || i - len < 0 || s[i+len] != s[i-len]) {
                    break;
                }
                int tmpStart = i - len;
                int tmpEnd = i + len;
                int tmpLen = tmpEnd - tmpStart + 1;
                if ( tmpLen > maxLen ) {
                    start = tmpStart;
                    end = tmpEnd;
                    maxLen = end - start + 1;
                }
            }
            for ( int len = 0 ; len < n ; ++len ) {
                if ( i - len < 0 || i + len + 1 > n || s[i-len] != s[i + len + 1] ) {
                    break;
                }
                int tmpStart = i - len;
                int tmpEnd = i + len + 1;
                int tmpLen = tmpEnd - tmpStart + 1;
                if ( tmpLen > maxLen ) {
                    start = tmpStart;
                    end = tmpEnd;
                    maxLen = end - start + 1;
                }
            }

        }
        for ( int i = start ; i <= end ; ++i ) {
            ans += s[i];
        }
        return ans;
    }
};
