class Solution {
public:
    string shortestPalindrome(string s) {
        string temp = s;
        string t = s;
        reverse(t.begin(),t.end());
        s = s + "@" + t;
        int n = s.size();
        s = " " + s;
        vector<int> kmp(n+1,0);
        int k = 0;
        kmp[1] = 0;
        for ( int i = 2 ; i <= n ; ++i ) {
            while ( k > 0 && s[i] != s[k+1] ) {
                k = kmp[k];
            }
            kmp[i] = (s[i] == s[k+1] ) ? ++k : 0;
        }
        int l = kmp[n];
        t = temp.substr(l);
        reverse(t.begin(),t.end());
        string ans = t + temp;
        return ans;
    }
};
