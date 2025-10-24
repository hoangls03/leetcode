class Solution {
public:
    bool balance( int n ) {
        vector<int> mark(10,0);
        while ( n > 0 ) {
            int d = n%10;
            mark[d]++;
            n /= 10;
        }
        for ( int i = 0 ; i <= 9 ; ++i ) {
            if ( mark[i] != 0 && mark[i] != i ) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        n++;
        while ( !balance(n) ) {
            n++;
        }
        return n;
    }
};
