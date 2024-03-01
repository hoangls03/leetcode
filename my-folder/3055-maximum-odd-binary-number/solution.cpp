class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size() - 1;
        int mark[2];
        mark[0] = mark[1] = 0;
        for ( int i = 0 ; i <= n ; ++i ) {
            mark[s[i] - '0']++;
        }
        s[n] = '1';
        mark[1]--;
        cout<<mark[1]<<'\n';
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[1] ) {
                s[i] = '1';
                mark[1]--;
            }
            else s[i] = '0';
        }
        return s;
    }
};
