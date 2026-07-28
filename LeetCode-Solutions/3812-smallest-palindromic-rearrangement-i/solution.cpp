class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> countCh('z' + 1,0);
        for ( int i = 0 ; i < n/2 ; ++i ) {
            countCh[s[i]]++;
        }

        string ans = "";
        for ( char i = 'a' ; i <= 'z' ; ++i ) {
            while ( countCh[i] ) {
                ans += i;
                countCh[i]--;
            }
        }
        if ( n & 1 ) {
            ans += s[n/2];
        }

        int pos = n/2 - 1;
        while ( pos >= 0 ) {
            ans += ans[pos];
            pos--;
        }

        return ans;
    }
};
