class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        s = " " + s;
        vector<long long> curLen(n + 1,0);
        k++;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( s[i] == '*' ) {
                curLen[i] = max(curLen[i-1] - 1,0LL);
            } else if ( s[i] == '#' ) {
                curLen[i] = curLen[i-1] * 2;
            } else if ( s[i] == '%' ) {
                curLen[i] = curLen[i-1];
            } else {
                curLen[i] = curLen[i-1] + 1;
            }
        } 
        if ( k > curLen[n] ) {
            return '.';
        }
        cout<<k<<'\n';
        for ( int i = n ; i >= 1 ; --i ) {
            if ( s[i] == '*' ) {
                continue;
            } else if ( s[i] == '#' ) {
                if ( k > curLen[i]/2 ) {
                    k -= curLen[i]/2;
                }
            } else if ( s[i] == '%' ) {
                k = curLen[i] - k + 1;
            } else {
                if ( k == curLen[i] ) {
                    return s[i];
                }
            }
        }
        return s[k];
    }
};
