class Solution {
public:
    int numSquares(int n) {
        vector<int> count(1e5,-1);
        int ans = 5;
        count[0] = 0;
        for ( int  i = 1 ; i <= sqrt(n) ; ++i ) {
            count[i*i] = 1;
        }
        for ( int i = 0 ; i <= sqrt(n) ; ++i ) {
            for ( int j = 0 ; j <= sqrt(n-i*i) ; ++j ) {
                if ( count[i*i+j*j] == -1 ) count[i*i + j*j] = 2;
            }
        }
        for ( int i = 0 ; i <= sqrt(n) ; ++i ) {
            for ( int j = 0 ; j <= sqrt(n-i*i) ; ++j ) {
                if ( n-i*i-j*j >= 0 && count[n-i*i-j*j] != -1 ) {
                    ans = min(ans,(i!=0) + (j != 0) + count[n-i*i-j*j]);
                }
            }
        }
        return ans;
    }
};
