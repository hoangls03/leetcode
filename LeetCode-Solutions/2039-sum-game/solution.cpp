class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int q1 = 0, q2 = 0, s1 = 0, s2 = 0;
        int m = n/2;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( num[i] == '?' ) {
                q1 += (i < m);
                q2 += (i >= m);
            } else {
                if ( i < m ) {
                    s1 += num[i] - '0';
                } else {
                    s2 += num[i] - '0';
                }
            }
        }
        if ( (q1 + q2) & 1 ) return true;

        return (2*s1 + 9*q1) != (2*s2 + 9*q2);
    }
};
